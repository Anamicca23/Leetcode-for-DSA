class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:

        n = len(nums)

        mp = {}

        for i in range(n):
            mp[nums[i]] = mp.get(nums[i], 0) + 1

        if k == len(nums):
            return max(nums)

        if k == 1:
            maxValue = -1

            for i in range(n):
                if mp[nums[i]] == 1 and nums[i] > maxValue:
                    maxValue = nums[i]

            return maxValue

        n = n - 1

        if nums[0] == nums[n]:
            return -1

        if mp[nums[0]] == 1 and mp[nums[n]] == 1:
            return max(nums[0], nums[n])

        if mp[nums[0]] == 1 and mp[nums[n]] > 1:
            return nums[0]

        if mp[nums[n]] == 1 and mp[nums[0]] > 1:
            return nums[n]

        return -1