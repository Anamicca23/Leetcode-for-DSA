class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        n = len(nums)
        res = 0
        sum_ = 0
        i = 0

        for j in range(n):
            sum_ += nums[j]
            while i <= j and sum_ * (j - i + 1) >= k:
                sum_ -= nums[i]
                i += 1
            res += (j - i + 1)
        
        return res
