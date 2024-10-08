class Solution:
    def minSwaps(self, s: str) -> int:
        i = 0
        j = len(s) - 1
        cur = 0
        swaps = 0
        
        s = list(s) 
        
        while i < j:
            if s[i] == '[':
                cur += 1
            else:
                cur -= 1
            
            if cur < 0:
                while s[j] != '[':
                    j -= 1
                s[i], s[j] = s[j], s[i]
                swaps += 1
                cur = 1
            
            i += 1
        
        return swaps