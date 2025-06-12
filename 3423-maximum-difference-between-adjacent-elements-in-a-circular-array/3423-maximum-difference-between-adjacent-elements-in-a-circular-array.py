class Solution(object):
    def maxAdjacentDistance(self, nums):
        diff = abs(nums[-1] - nums[0])
        for i in range(1, len(nums)):
            diff = max(diff, abs(nums[i] - nums[i - 1]))
        return diff