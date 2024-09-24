class TrieNode {
    TrieNode[] children = new TrieNode[10];
    boolean isTerminal = false;
}

class Trie {
    TrieNode root = new TrieNode();

    public void insert(int data) {
        TrieNode node = root;
        int divisor = (int) Math.pow(10, (int) Math.log10(data));
        while (divisor > 0) {
            int digit = (data / divisor) % 10;
            if (node.children[digit] == null) node.children[digit] = new TrieNode();
            node = node.children[digit];
            divisor /= 10;
        }
        node.isTerminal = true;
    }

    public int prefixLen(int data) {
        TrieNode node = root;
        int len = 0;
        int divisor = (int) Math.pow(10, (int) Math.log10(data));
        while (divisor > 0) {
            int digit = (data / divisor) % 10;
            if (node.children[digit] == null) return len;
            node = node.children[digit];
            len++;
            divisor /= 10;
        }
        return len;
    }
}

class Solution {
    Trie trie = new Trie();

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        for (int num : arr1) trie.insert(num);
        int maxLen = 0;
        for (int num : arr2) maxLen = Math.max(trie.prefixLen(num), maxLen);
        return maxLen;
    }
}
