class Solution:
    def minSumOfLengths(self, A: List[int], k: int) -> int:
        n = len(A)
        res, tot, i = n + 1, 0, 0

        dp = [n] * (n + 1)

        for j in range(n):
            tot += A[j]

            while tot > k:
                tot -= A[i]
                i += 1
            dp[j + 1] = dp[j]

            if tot == k:
                res = min(res, j - i + 1 + dp[i])
                dp[j + 1] = min(dp[j], j - i + 1)

        return -1 if res == n + 1 else res