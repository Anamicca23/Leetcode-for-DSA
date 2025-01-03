class Solution:
    def waysToSplitArray(self, nums):
        n = len(nums)
        total_sum = sum(nums)
        left_sum = 0
        split_count = 0

        for i in range(n - 1):
            left_sum += nums[i]
            right_sum = total_sum - left_sum
            if left_sum >= right_sum:
                split_count += 1
        
        return split_count
