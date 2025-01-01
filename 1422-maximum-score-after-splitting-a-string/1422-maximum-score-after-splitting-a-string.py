class Solution:
    def maxScore(self, s: str) -> int:
        ret = 0
        n = len(s)
        v = [0] * n
        for i in range(n):
            if i - 1 >= 0:
                v[i] += v[i - 1]
            v[i] += s[i] == '0'
        
        one = 0
        for i in range(n - 1, 0, -1):
            one += s[i] == '1'
            ret = max(ret, v[i - 1] + one)
        
        return ret
