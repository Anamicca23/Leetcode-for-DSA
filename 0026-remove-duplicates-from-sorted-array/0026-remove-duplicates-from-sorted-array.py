class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        modIdx = 1
        for i in range(len(nums) - 1):
            if nums[i] != nums[i + 1]:
                nums[modIdx] = nums[i + 1]
                modIdx += 1
        return modIdx
