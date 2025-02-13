from sortedcontainers import *
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums = SortedList(nums)
        a = 0
        while nums[0] < k:
            b = nums.pop(0)
            c = nums.pop(0)
            d = min(b, c) * 2 + max(b, c)
            nums.add(d)
            a += 1
        return a