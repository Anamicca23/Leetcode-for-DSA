class Solution:
    def minimumDistance(self, A):
        def d(a, b):
            return abs(a // 6 - b // 6) + abs(a % 6 - b % 6)

        A = [ord(c) - 65 for c in A]
        dp = [0] * 26

        for b, c in zip(A, A[1:]):
            dp[b] = max(dp[a] + d(b, c) - d(a, c) for a in range(26))

        return sum(d(b, c) for b, c in zip(A, A[1:])) - max(dp)
