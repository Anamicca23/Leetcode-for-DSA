class Solution:
    def maxDistance(self, nums1: list[int], nums2: list[int]) -> int:
        i, j = 0, 0
        max_dist = 0

        while i < len(nums1) and j < len(nums2):
            if nums1[i] <= nums2[j]:
                max_dist = max(max_dist, j - i)
                j += 1
            else:
                i += 1

        return max_dist