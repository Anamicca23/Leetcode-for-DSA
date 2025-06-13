class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        l2, m = 0, len(nums2)
        for x in nums1:
            while l2 < m and nums2[l2] < x:
                l2 += 1
            if l2 < m and nums2[l2] == x:
                return x
        return -1