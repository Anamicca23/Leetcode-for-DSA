class Solution:
    def __init__(self):
        self.res = []

    def twosum(self, nums, targ, i, j):
        while i < j:
            sum_ = nums[i] + nums[j]
            if sum_ < targ:
                i += 1
            elif sum_ > targ:
                j -= 1
            else:
                self.res.append([-targ, nums[i], nums[j]])
                while i < j and nums[i] == nums[i + 1]:
                    i += 1
                while i < j and nums[j] == nums[j - 1]:
                    j -= 1
                i += 1
                j -= 1

    def threeSum(self, nums):
        n = len(nums)
        if n < 3:
            return []

        nums.sort()
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            targ = -nums[i]
            self.twosum(nums, targ, i + 1, n - 1)
        return self.res
