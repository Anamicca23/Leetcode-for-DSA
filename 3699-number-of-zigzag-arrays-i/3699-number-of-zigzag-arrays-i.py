class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 1000000007
        m = r - l + 1
        dp = [1] * m
        for _ in range(2, n + 1):
            dp.reverse()
            pref = 0
            for i in range(m):
                old = dp[i]
                dp[i] = pref
                pref = (pref + old) % MOD
        ans = sum(dp) % MOD
        return (ans * 2) % MOD