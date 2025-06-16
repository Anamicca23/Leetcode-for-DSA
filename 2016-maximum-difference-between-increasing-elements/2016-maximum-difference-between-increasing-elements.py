class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        max_uptil_now = nums[n-1]
        ans = -1
        for i in range(n-2,-1,-1):
            if nums[i]>=max_uptil_now:
                max_uptil_now=nums[i]
            else:
                ans = max(ans,max_uptil_now-nums[i])
        return ans
            