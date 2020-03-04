/*******************************************************************************
 * This file is part of the Incubed project.
 * Sources: https://github.com/slockit/in3-c
 * 
 * Copyright (C) 2018-2020 slock.it GmbH, Blockchains LLC
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

package in3.eth1;

import in3.*;

/**
 * represents a Transaction receipt in ethereum.
 * 
 */

public class TransactionReceipt {

  private JSON data;

  private TransactionReceipt(JSON data) {
    this.data = data;
  }

  protected static TransactionReceipt asTransactionReceipt(Object o) {
    return o == null ? null : new TransactionReceipt((JSON) o);
  }

  /**
     * the blockhash of the block containing this transaction.
     */
  public String getBlockHash() {
    return data.getString("blockHash");
  }

  /**
     * the block number of the block containing this transaction.
     */
  public long getBlockNumber() {
    return data.getLong("blockNumber");
  }

  /**
     * the address of the deployed contract (if successfull)
     */
  public String getCreatedContractAddress() {
    return data.getString("contractAddress");
  }

  /**
     * the address of the sender.
     */
  public String getFrom() {
    return data.getString("from");
  }

  /**
     * the Transaction hash.
     */
  public String getTransactionHash() {
    return data.getString("transactionHash");
  }

  /**
     * the Transaction index.
     */
  public int getTransactionIndex() {
    return JSON.asInt(data.get("transactionIndex"));
  }

  /**
     * 20 Bytes - The address of the receiver. null when it's a contract creation
     * transaction.
     */
  public String getTo() {
    return data.getString("to");
  }

  /**
     * The amount of gas used by this specific transaction alone.
     */
  public long getGasUsed() {
    return data.getLong("gasUsed");
  }

  /**
     * Array of log objects, which this transaction generated.
     */
  public Log[] getLogs() {
    return Log.asLogs(data.get("logs"));
  }

  /**
     * 256 Bytes - A bloom filter of logs/events generated by contracts during
     * transaction execution. Used to efficiently rule out transactions without
     * expected logs
     */
  public String getLogsBloom() {
    return data.getString("logsBloom");
  }

  /**
     * 32 Bytes - Merkle root of the state trie after the transaction has been
     * executed (optional after Byzantium hard fork EIP609).
     */
  public String getRoot() {
    return data.getString("root");
  }

  /**
     * success of a Transaction.
     * 
     * true indicates transaction failure , false indicates transaction success. Set
     * for blocks mined after Byzantium hard fork EIP609, null before.
     */
  public boolean getStatus() {
    return data.getLong("status") == 1;
  }
}
