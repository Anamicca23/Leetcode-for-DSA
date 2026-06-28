class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, A: list[int]) -> int:
        n = len(A)
        freq = [0] * (n + 1)
        for x in A:
            freq[min(x, n)] += 1
        res = 1
        for i in range(2, n + 1):
            res = min(res + freq[i], i)
        return res