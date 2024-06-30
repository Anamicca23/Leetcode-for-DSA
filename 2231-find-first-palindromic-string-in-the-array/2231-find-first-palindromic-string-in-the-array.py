class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
    
    def firstPalindrome(self, words: list[str]) -> str:
        for word in words:
            if self.isPalindrome(word):
                return word
        return ""
