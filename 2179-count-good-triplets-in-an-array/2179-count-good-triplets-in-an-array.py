class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        res, inds, arr = 0, [0]*len(nums1), SortedList()
        for i,num in enumerate(nums1):      
            inds[num] = i
        for i,num in enumerate(nums2):      
            nums1[i] = inds[num]
        for i,num in enumerate(nums1[::-1]):
            ind = arr.bisect(num)
            res += (i-ind)*(num-ind)
            arr.add(num)
        return res