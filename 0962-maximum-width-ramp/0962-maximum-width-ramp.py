class Solution:
    def maxWidthRamp(self, nums: list[int]) -> int:
        n = len(nums)
        mwramp = 0
        rmax = [0] * n
        rmax[n - 1] = nums[n - 1]

        # Fill the rmax array with the maximum values from the right
        for i in range(n - 2, -1, -1):
            rmax[i] = max(rmax[i + 1], nums[i])

        i, j = 0, 0
        while j < n:
            # Increment i until the condition is satisfied
            while i < j and nums[i] > rmax[j]:
                i += 1
            mwramp = max(mwramp, j - i)  # Update the maximum width ramp
            j += 1
        
        return mwramp
