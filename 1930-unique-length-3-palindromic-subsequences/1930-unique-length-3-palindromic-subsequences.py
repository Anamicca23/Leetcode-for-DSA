class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ans = 0
        
        for i in range(26):
            l = s.find(chr(ord('a') + i))
            if l == -1:
                continue
            r = s.rfind(chr(ord('a') + i))
            if r - l < 2:
                continue
            
            unique_chars = set()
            for k in range(l + 1, r):
                unique_chars.add(s[k])
                if len(unique_chars) == 26:
                    break
            ans += len(unique_chars)
        
        return ans
