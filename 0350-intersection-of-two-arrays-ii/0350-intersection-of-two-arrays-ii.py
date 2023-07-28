class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort() # Sort nums1 in ascending order
        nums2.sort() # Sort nums2 in ascending order
        n, m = len(nums1), len(nums2)

        ans = []
        i, j = 0, 0
        # Two pointer approach to find the intersection of sorted arrays
        while i < n and j < m:
            if nums1[i] > nums2[j]:
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                ans.append(nums1[i]) # Add common element to the list
                i += 1
                j += 1

        return ans
