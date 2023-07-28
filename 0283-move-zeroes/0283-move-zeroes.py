class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Two Pointer Approach
        i, j = 0, 0
        # Move non-zero elements to the beginning of the list
        while j < len(nums):
            if nums[j] == 0:
                j += 1
            else:
                nums[i] = nums[j]
                i += 1
                j += 1
        # Fill the remaining positions with zeros
        while i < len(nums):
            nums[i] = 0
            i += 1
        
         #After the execution of the code,
        #all zeros in the array/list will be moved to the end, 
        #and the relative order of the non-zero elements will be preserved.
    
   # TC:=O(n)
   # SC:=O(1)