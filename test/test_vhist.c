#ifndef TEST
#define TEST
#endif
#define DEBUG

#include <core/client/keys.h>
#include <core/util/data.h>
#include <core/util/mem.h>
#include <eth_nano/vhist.h>
#include <inttypes.h>
#include <transport_curl/in3_storage.h>

#include "test_utils.h"

static struct timeval begin, end;

static char* filetostr(const char* filename) {
  char* buffer = NULL;
  long  length;
  FILE* f = fopen(filename, "r");
  if (f) {
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = _malloc(length);
    if (buffer) {
      fread(buffer, 1, length, f);
    }
    fclose(f);
  }
  return buffer;
}

static void bb_print(bytes_builder_t* bb) {
  for (int i = 0; i < bb->b.len; i += 20) {
    ba_print(&bb->b.data[i], 20);
    printf("\n");
  }
}

static bool vh_diff_matches(uint64_t block) {
  d_iterator_t sitr;
  char*        nodeliststr = filetostr("../test/testdata/tobalaba_nodelist.json");
  json_ctx_t*  jnl         = parse_json(nodeliststr);
  if (jnl == NULL) return false;

  d_token_t *ss = d_get(jnl->result, K_STATES), *vs = NULL;
  vhist_t*   vh = vh_new();
  for (sitr = d_iter(ss); sitr.left; d_iter_next(&sitr)) {
    vh_add_state(vh, sitr.token, false);
  }

  bytes_builder_t* bb  = vh_get_for_block(vh, block);
  uint64_t         blk = 0;
  bytes_t          *b;
  bytes_builder_t* bb_ = bb_new();
  for (sitr = d_iter(ss); sitr.left; d_iter_next(&sitr)) {
    vs  = d_get(sitr.token, K_VALIDATORS);
    blk = d_get_longk(sitr.token, K_BLOCK);
    if (blk > block) break;
    bb_clear(bb_);
    if (d_type(vs) == T_ARRAY) {
      for (d_iterator_t vitr = d_iter(vs); vitr.left; d_iter_next(&vitr)) {
        b = (d_type(vitr.token) == T_STRING) ? hex2byte_new_bytes(d_string(vitr.token), 40) : d_bytesl(vitr.token, 20);
        bb_write_fixed_bytes(bb_, b);
        if (d_type(vitr.token) == T_STRING) _free(b->data);
      }
    }
  }
  //  printf("-------\n");
  //  bb_print(bb_);

  bool ret = bytes_cmp(bb->b, bb_->b) != 0;
  bb_free(bb_);
  bb_free(bb);
  vh_free(vh);
  free_json(jnl);
  _free(nodeliststr);
  return ret;
}

static void test_vh_diff() {
  TEST_ASSERT_TRUE(vh_diff_matches(11540950));
  TEST_ASSERT_TRUE(vh_diff_matches(11540919));
  TEST_ASSERT_TRUE(vh_diff_matches(11540920));
  TEST_ASSERT_TRUE(vh_diff_matches(11540918));
  TEST_ASSERT_TRUE(vh_diff_matches(12851669));
  TEST_ASSERT_TRUE(vh_diff_matches(10120180));
  TEST_ASSERT_TRUE(vh_diff_matches(9814665));
  TEST_ASSERT_TRUE(vh_diff_matches(4723940));
  TEST_ASSERT_TRUE(vh_diff_matches(1946064));
  TEST_ASSERT_TRUE(vh_diff_matches(582));
  TEST_ASSERT_TRUE(vh_diff_matches(0));
}

static void test_vh_cache() {
  char*       nodeliststr = filetostr("../test/testdata/tobalaba_nodelist.json");
  json_ctx_t* jnl         = parse_json(nodeliststr);
  TEST_ASSERT_NOT_NULL(jnl);

  in3_storage_handler_t storage_handler;
  storage_handler.get_item = storage_get_item;
  storage_handler.set_item = storage_set_item;

  in3_t* c        = in3_new();
  c->requestCount = 1;
  c->cacheStorage = &storage_handler;

  vhist_t* vh = vh_init_nodelist(jnl->result);
  TEST_ASSERT_NOT_NULL(vh);
  vh_cache_save(vh, c);

  vhist_t* vh_cached = vh_cache_retrieve(c);
  TEST_ASSERT_NOT_NULL(vh_cached);
  TEST_ASSERT_EQUAL_MEMORY(vh->diffs->b.data, vh_cached->diffs->b.data, vh->diffs->b.len);
  TEST_ASSERT_EQUAL_MEMORY(vh->vldtrs->b.data, vh_cached->vldtrs->b.data, vh->vldtrs->b.len);
  TEST_ASSERT_EQUAL_UINT64(vh->last_change_block, vh_cached->last_change_block);
  vh_free(vh_cached);
  vh_free(vh);
  in3_free(c);
  free_json(jnl);
  _free(nodeliststr);
}

/*
 * Main
 */
int main() {
  TESTS_BEGIN();
  RUN_TIMED_TEST(test_vh_diff);
  RUN_TIMED_TEST(test_vh_cache);
  return TESTS_END();
}
