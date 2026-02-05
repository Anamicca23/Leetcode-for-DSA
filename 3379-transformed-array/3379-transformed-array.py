class Solution:
    def constructTransformedArray(self, A: List[int]) -> List[int]:
        n = len(A)
        OFFSET = 1 << 7
        MASK = (1 << 8) - 1

        for i in range(n):
            A[i] += OFFSET

        for i in range(n):
            cur = A[i] - OFFSET
            idx = ((i + cur) % n + n) % n
            val = A[idx] & MASK
            A[i] |= val << 8

        for i in range(n):
            A[i] = (A[i] >> 8) - OFFSET

        return A
