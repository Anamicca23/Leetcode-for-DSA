class Solution:
    def stoneGameVIII(self, A: List[int]) -> int:
        n = len(A)
        for i in range(1, n):
            A[i] += A[i - 1]
        ans = A[-1]
        for i in range(n - 2, 0, -1):
            ans = max(ans, A[i] - ans)
        return ans