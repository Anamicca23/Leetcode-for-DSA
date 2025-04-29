from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums) - 2
        
        # Step 1: Find the first decreasing element from the end
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1

        # Step 2: Find the next larger element and swap
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # Step 3: Reverse the suffix
        nums[i + 1:] = reversed(nums[i + 1:])
