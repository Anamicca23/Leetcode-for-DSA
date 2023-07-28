class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # keep track of the next position to place an even number.
        j = 0
        for i in range(len(nums)):
            # it checks if the number is even by checking if nums[i] % 2 == 0.
            # If it is even, it means it should be placed at the next available position for even numbers.
            if nums[i] % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                # After swapping, it increments j to update the next available position for even numbers.
                j += 1
        return nums
        # Finally, it returns the modified nums list as the sorted array by parity.
