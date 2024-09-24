#pragma GCC optimize("O3", "unroll-loops")
class TrieNode {
public:
    TrieNode* children[10] = {};
    bool isTerminal = false;
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(int data) {
        TrieNode* node = root;
        for (int divisor = pow(10, (int)log10(data)); divisor > 0; divisor /= 10) {
            int digit = (data / divisor) % 10;
            if (!node->children[digit]) node->children[digit] = new TrieNode();
            node = node->children[digit];
        }
        node->isTerminal = true;
    }

    int prefixLen(int data) {
        TrieNode* node = root;
        int len = 0;
        for (int divisor = pow(10, (int)log10(data)); divisor > 0; divisor /= 10) {
            int digit = (data / divisor) % 10;
            if (!node->children[digit]) return len;
            node = node->children[digit], len++;
        }
        return len;
    }
};

class Solution {
    Trie trie;
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for (int num : arr1) trie.insert(num);
        int maxLen = 0;
        for (int num : arr2) maxLen = max(trie.prefixLen(num), maxLen);
        return maxLen;
    }
};
