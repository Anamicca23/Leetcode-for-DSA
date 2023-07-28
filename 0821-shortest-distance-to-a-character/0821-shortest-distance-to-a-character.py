class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        pos = -1000000000 # Initialize a very large negative value for pos
        ans = [n] * n
        
        for i in range(n):
            if s[i] == c:
                pos = i
            ans[i] = min(ans[i], abs(i - pos))
        
        for i in range(n - 1, -1, -1):
            if s[i] == c:
                pos = i
            ans[i] = min(ans[i], abs(i - pos))
        
        return ans
