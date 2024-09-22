class Solution:
    # Function to calculate the gap between numbers a and b in the lexicographical tree
    def getGap(self, a: int, b: int, n: int) -> int:
        gap = 0
        while a <= n:
            gap += min(n + 1, b) - a
            a *= 10
            b *= 10
        return gap

    # Function to find the k-th smallest number in lexicographical order
    def findKthNumber(self, n: int, k: int) -> int:
        cur = 1
        i = 1
        while i < k:
            gap = self.getGap(cur, cur + 1, n)
            if i + gap <= k:
                i += gap
                cur += 1
            else:
                i += 1
                cur *= 10
        return cur