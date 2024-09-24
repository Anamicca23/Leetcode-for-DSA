class TrieNode:
    def __init__(self):
        self.children = [None] * 10
        self.isTerminal = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, data):
        node = self.root
        divisor = 10 ** int(len(str(data)) - 1)
        while divisor > 0:
            digit = (data // divisor) % 10
            if node.children[digit] is None:
                node.children[digit] = TrieNode()
            node = node.children[digit]
            divisor //= 10
        node.isTerminal = True

    def prefixLen(self, data):
        node = self.root
        length = 0
        divisor = 10 ** int(len(str(data)) - 1)
        while divisor > 0:
            digit = (data // divisor) % 10
            if node.children[digit] is None:
                return length
            node = node.children[digit]
            length += 1
            divisor //= 10
        return length

class Solution:
    def __init__(self):
        self.trie = Trie()

    def longestCommonPrefix(self, arr1, arr2):
        for num in arr1:
            self.trie.insert(num)
        max_len = 0
        for num in arr2:
            max_len = max(self.trie.prefixLen(num), max_len)
        return max_len
