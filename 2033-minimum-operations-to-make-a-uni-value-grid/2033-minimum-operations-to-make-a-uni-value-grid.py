class Solution(object):
    def minOperations(self, grid, x):
        nums = [k for row in grid for k in row]
        nums.sort()
        target = nums[len(nums) // 2]
        totalOperations = 0
        for k in nums:
            temp = abs(k - target)
            if temp % x != 0:
                return -1
            totalOperations += temp // x
        return totalOperations