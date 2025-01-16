class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        return (len(nums2)%2*reduce(ixor, nums1))^(len(nums1)%2*reduce(ixor, nums2))
        