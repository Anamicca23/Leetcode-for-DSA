class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        if k == len(nums):
            return max(nums)
        if k == 1:
            arr = [x for x in nums if nums.count(x) == 1]
        else:
            arr = [x for x in (nums[0], nums[-1]) if nums.count(x) == 1]
        return max(arr) if arr else -1