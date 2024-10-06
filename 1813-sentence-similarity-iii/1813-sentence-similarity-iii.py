class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        # Split the sentences into words
        words1 = sentence1.split()
        words2 = sentence2.split()
        
        # Two pointers from the start and end
        i, j = 0, 0
        n, m = len(words1), len(words2)
        
        # Move pointers from the start while the words are the same
        while i < n and i < m and words1[i] == words2[i]:
            i += 1
        
        # Move pointers from the end while the words are the same
        while j < (n - i) and j < (m - i) and words1[n - j - 1] == words2[m - j - 1]:
            j += 1
        
        # If the total matched words cover both sentences, they are similar
        return i + j == n or i + j == m