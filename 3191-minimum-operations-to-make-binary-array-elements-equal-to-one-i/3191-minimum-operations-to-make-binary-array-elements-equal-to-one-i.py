class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(2, len(nums)):

            # only looking forward to the last element
            if nums[i - 2] == 0:
                count += 1
                # flip i-2 and i-1 and i
                nums[i - 2] = nums[i - 2] ^ 1
                nums[i - 1] = nums[i - 1] ^ 1
                nums[i] = nums[i] ^ 1

        if sum(nums) == len(nums):
            return count
        return -1