class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            minim = 10**10
            index = 0
            for i in range(len(nums)):
                if nums[i] < minim:
                    minim = nums[i]
                    index = i
            nums[index] *= multiplier
        return nums