class Solution:
    def is_vowel(self, c):
        return c in {'a', 'e', 'i', 'o', 'u'}
    
    def vowelStrings(self, words, queries):
        n = len(words)
        csum = [0] * n
        sum_vowels = 0
        
        for i in range(n):
            if self.is_vowel(words[i][0]) and self.is_vowel(words[i][-1]):
                sum_vowels += 1
            csum[i] = sum_vowels
        
        res = []
        for l, r in queries:
            res.append(csum[r] - (csum[l - 1] if l > 0 else 0))
        
        return res
