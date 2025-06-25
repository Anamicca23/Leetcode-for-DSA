class Solution:
    def kthSmallestProduct(self, nums1, nums2, k):
        def separate(A):
            A1 = []
            A2 = []
            for a in A:
                if a < 0:
                    A1.append(-a)
                else:
                    A2.append(a)
            A1.reverse()
            return A1, A2

        def numProductNoGreaterThan(A, B, m):
            count = 0
            j = len(B) - 1
            for a in A:
                while j >= 0 and a * B[j] > m:
                    j -= 1
                count += j + 1
            return count

        A1, A2 = separate(nums1)
        B1, B2 = separate(nums2)

        negCount = len(A1) * len(B2) + len(A2) * len(B1)
        sign = 1

        if k > negCount:
            k -= negCount
        else:
            k = negCount - k + 1
            sign = -1
            B1, B2 = B2, B1

        l, r = 0, int(1e10)

        while l < r:
            m = (l + r) // 2
            if numProductNoGreaterThan(A1, B1, m) + numProductNoGreaterThan(A2, B2, m) >= k:
                r = m
            else:
                l = m + 1

        return sign * l