/*******************************************************************************
 * This file is part of the Incubed project.
 * Sources: https://github.com/slockit/in3-c
 * 
 * Copyright (C) 2018-2019 slock.it GmbH, Blockchains LLC
 * 
 * 
 * COMMERCIAL LICENSE USAGE
 * 
 * Licensees holding a valid commercial license may use this file in accordance 
 * with the commercial license agreement provided with the Software or, alternatively, 
 * in accordance with the terms contained in a written agreement between you and 
 * slock.it GmbH/Blockchains LLC. For licensing terms and conditions or further 
 * information please contact slock.it at in3@slock.it.
 * 	
 * Alternatively, this file may be used under the AGPL license as follows:
 *    
 * AGPL LICENSE USAGE
 * 
 * This program is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Affero General Public License as published by the Free Software 
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
 * PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
 * [Permissions of this strong copyleft license are conditioned on making available 
 * complete source code of licensed works and modifications, which include larger 
 * works using a licensed work, under the same license. Copyright and license notices 
 * must be preserved. Contributors provide an express grant of patent rights.]
 * You should have received a copy of the GNU Affero General Public License along 
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 *******************************************************************************/
#include "zksync.h"
#include "../../core/client/context_internal.h"
#include "../../core/client/keys.h"
#include "../../core/client/plugin.h"
#include "../../core/util/debug.h"
#include "../../core/util/mem.h"
#include "../../third-party/zkcrypto/lib.h"
#include "zk_helper.h"
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

static zk_sign_type_t get_sign_type(d_token_t* type) {
  if (type == NULL) return ZK_SIGN_PK;
  char* c = d_string(type);
  if (strcmp(c, "contract") == 0) return ZK_SIGN_CONTRACT;
  if (strcmp(c, "create2") == 0) return ZK_SIGN_CREATE2;
  return ZK_SIGN_PK;
}

// --- handle rpc----
static in3_ret_t zksync_rpc(zksync_config_t* conf, in3_rpc_handle_ctx_t* ctx) {
  char*      method = d_get_stringk(ctx->ctx->requests[0], K_METHOD);
  d_token_t* params = d_get(ctx->ctx->requests[0], K_PARAMS);
  if (strncmp(method, "zksync_", 7)) return IN3_EIGNORE;

  // do we have a provider?
  if (!conf->provider_url) {
    switch (ctx->ctx->client->chain_id) {
      case CHAIN_ID_MAINNET:
        conf->provider_url = _strdupn("https://api.zksync.io/jsrpc", -1);
        break;
      default:
        return ctx_set_error(ctx->ctx, "no provider_url in config", IN3_EINVAL);
    }
  }
  if (strcmp(method, "zksync_depositToSyncFromEthereum") == 0 || strcmp(method, "zksync_deposit") == 0) return zksync_deposit(conf, ctx, params);
  if (strcmp(method, "zksync_syncTransfer") == 0 || strcmp(method, "zksync_transfer") == 0) return zksync_transfer(conf, ctx, params, ZK_TRANSFER);
  if (strcmp(method, "zksync_withdraw") == 0) return zksync_transfer(conf, ctx, params, ZK_WITHDRAW);
  if (strcmp(method, "zksync_setKey") == 0) return zksync_set_key(conf, ctx, params);
  if (strcmp(method, "zksync_emergencyWithdraw") == 0) return zksync_emergency_withdraw(conf, ctx, params);
  if (strcmp(method, "zksync_getKey") == 0) {
    bytes32_t k;
    TRY(zksync_get_sync_key(conf, ctx->ctx, k))
    return in3_rpc_handle_with_bytes(ctx, bytes(k, 32));
  }
  if (strcmp(method, "zksync_getPubKeyHash") == 0) {
    bytes32_t k;
    address_t pubkey_hash;
    TRY(zksync_get_sync_key(conf, ctx->ctx, k))
    zkcrypto_pk_to_pubkey(k, pubkey_hash);
    char res[48];
    strcpy(res, "\"sync:");
    bytes_to_hex(pubkey_hash, 20, res + 6);
    strcpy(res + 46, "\"");
    return in3_rpc_handle_with_string(ctx, res);
  }
  if (strcmp(method, "zksync_contract_address") == 0) {
    uint8_t* adr;
    TRY(zksync_get_contracts(conf, ctx->ctx, &adr))
    sb_t* sb = in3_rpc_handle_start(ctx);
    sb_add_rawbytes(sb, "{\"govContract\":\"0x", bytes(conf->gov_contract, 20), 0);
    sb_add_rawbytes(sb, "\",\"mainContract\":\"0x", bytes(conf->main_contract, 20), 0);
    sb_add_chars(sb, "\"}");
    return in3_rpc_handle_finish(ctx);
  }
  if (strcmp(method, "zksync_tokens") == 0) {
    TRY(resolve_tokens(conf, ctx->ctx, NULL, NULL))
    sb_t* sb = in3_rpc_handle_start(ctx);
    sb_add_char(sb, '{');
    for (unsigned int i = 0; i < conf->token_len; i++) {
      if (i) sb_add_char(sb, ',');
      sb_add_char(sb, '\"');
      sb_add_chars(sb, conf->tokens[i].symbol);
      sb_add_rawbytes(sb, "\":{\"address\":\"0x", bytes(conf->tokens[i].address, 20), 0);
      sb_add_chars(sb, "\",\"decimals\":");
      sb_add_int(sb, conf->tokens[i].decimals);
      sb_add_chars(sb, ",\"id\":");
      sb_add_int(sb, conf->tokens[i].id);
      sb_add_chars(sb, ",\"symbol\":\"");
      sb_add_chars(sb, conf->tokens[i].symbol);
      sb_add_chars(sb, "\"}");
    }
    sb_add_char(sb, '}');
    return in3_rpc_handle_finish(ctx);
  }
  str_range_t p            = d_to_json(params);
  char*       param_string = alloca(p.len - 1);
  memcpy(param_string, p.data + 1, p.len - 2);
  param_string[p.len - 2] = 0;

  if (strcmp(method, "zksync_account_info") == 0 && *param_string == 0) {
    TRY(zksync_get_account(conf, ctx->ctx, NULL))
    param_string = alloca(45);
    set_quoted_address(param_string, conf->account);
  }
  if (strcmp(method, "zksync_ethop_info") == 0)
    sprintf(param_string, "%i", d_get_int_at(params, 0));

  d_token_t* result;
  TRY(send_provider_request(ctx->ctx, conf, method + 7, param_string, &result))

  char* json = d_create_json(NULL, result);
  in3_rpc_handle_with_string(ctx, json);
  _free(json);
  return IN3_OK;
}

static in3_ret_t handle_zksync(void* cptr, in3_plugin_act_t action, void* arg) {
  zksync_config_t* conf = cptr;
  switch (action) {
    case PLGN_ACT_TERM: {
      if (conf->provider_url) _free(conf->provider_url);
      if (conf->main_contract) _free(conf->main_contract);
      if (conf->account) _free(conf->account);
      _free(conf);
      return IN3_OK;
    }

    case PLGN_ACT_CONFIG_GET: {
      in3_get_config_ctx_t* ctx = arg;
      sb_add_chars(ctx->sb, ",\"zksync\":{\"provider_url\":\"");
      sb_add_chars(ctx->sb, conf->provider_url ? conf->provider_url : "");
      sb_add_char(ctx->sb, '\"');
      if (conf->account) {
        bytes_t ac = bytes(conf->account, 20);
        sb_add_bytes(ctx->sb, ",\"account\"=", &ac, 1, false);
      }
      sb_add_chars(ctx->sb, ",\"signer_type\":\"");
      if (conf->sign_type == ZK_SIGN_CONTRACT)
        sb_add_chars(ctx->sb, "contract\"");
      else if (conf->sign_type == ZK_SIGN_CREATE2)
        sb_add_chars(ctx->sb, "create2\"");
      else
        sb_add_chars(ctx->sb, "pk\"");
      sb_add_char(ctx->sb, '}');
      return IN3_OK;
    }

    case PLGN_ACT_CONFIG_SET: {
      in3_configure_ctx_t* ctx = arg;
      if (ctx->token->key == key("zksync")) {
        const char* provider = d_get_string(ctx->token, "provider_url");
        if (provider) conf->provider_url = _strdupn(provider, -1);
        bytes_t* account = d_get_bytes(ctx->token, "account");
        if (account && account->len == 20) memcpy(conf->account = _malloc(20), account->data, 20);
        bytes_t* main_contract = d_get_bytes(ctx->token, "main_contract");
        if (main_contract && main_contract->len == 20) memcpy(conf->main_contract = _malloc(20), main_contract->data, 20);
        conf->sign_type = get_sign_type(d_get(ctx->token, key("signer_type")));
        return IN3_OK;
      }
      return IN3_EIGNORE;
    }

    case PLGN_ACT_RPC_HANDLE:
      return zksync_rpc(conf, arg);

    default:
      return IN3_ENOTSUP;
  }

  return IN3_EIGNORE;
}

in3_ret_t in3_register_zksync(in3_t* c) {
  return plugin_register(c, PLGN_ACT_RPC_HANDLE | PLGN_ACT_TERM | PLGN_ACT_CONFIG_GET | PLGN_ACT_CONFIG_SET, handle_zksync, _calloc(sizeof(zksync_config_t), 1), false);
}