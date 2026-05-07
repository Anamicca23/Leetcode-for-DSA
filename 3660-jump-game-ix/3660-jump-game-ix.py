class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [nums[0]]
        for i in range(1, n):
            res.append(max(res[-1], nums[i]))

        min_idx = n - 1
        for i in range(n - 2, -1, -1):
            if res[i] > nums[min_idx]:
                res[i] = res[min_idx]
            if nums[i] < nums[min_idx]:
                min_idx = i
        return res