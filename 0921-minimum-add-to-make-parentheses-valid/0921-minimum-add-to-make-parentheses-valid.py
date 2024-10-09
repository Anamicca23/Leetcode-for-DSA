class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        size = 0
        openb = 0
        
        for c in s:
            if c == '(':
                size += 1
            else:
                if size > 0:
                    size -= 1
                else:
                    openb += 1
        
        return openb + size