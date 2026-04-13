class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        n = len(nums)
        d = n
        for i in range(n):
            if nums[i] == target:
                cur = abs(i - start)
                if d > cur:
                    d = cur
        return d