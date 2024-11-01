class Solution:
    def makeFancyString(self, s: str) -> str:
        if len(s) < 3:
            return s
        
        result = s[:2]
        j = 2
        
        for i in range(2, len(s)):
            if s[i] != result[j - 1] or s[i] != result[j - 2]:
                result += s[i]
                j += 1
        
        return result
