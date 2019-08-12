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
     * 20 Bytes - The address of the receiver. null when it’s a contract creation
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
