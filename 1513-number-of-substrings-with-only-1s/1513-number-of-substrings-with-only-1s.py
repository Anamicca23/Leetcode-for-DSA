class Solution:
    def numSub(self, s: str) -> int:
        MOD = 10**9 + 7
        cur = 0
        ans = 0
        for c in s:
            if c == '1':
                cur = (cur + 1) % MOD
            else:
                cur = 0
            ans = (ans + cur) % MOD
        return ans