class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        # Two pointers
        # The code copies each element from nums2 to the end of nums1,
        # and then sorts the entire nums1 array
        # to make sure it is sorted in ascending order.
        i, j = m, 0
        for j in range(n):
            nums1[i] = nums2[j]
            i += 1
        nums1.sort()
