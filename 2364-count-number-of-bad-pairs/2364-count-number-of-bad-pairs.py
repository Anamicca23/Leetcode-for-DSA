from collections import Counter

class Solution:
    def countBadPairs(self, nums):
        b = len(nums)
        for i in range(b):
            nums[i] = i - nums[i]

        freq = Counter(nums)
        g = sum((v * (v - 1)) // 2 for v in freq.values())

        return (b * (b - 1)) // 2 - g
