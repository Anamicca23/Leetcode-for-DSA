class Solution:
    def findLengthOfShortestSubarray(self, arr):
        n = len(arr)
        left, right = 0, n - 1
        
        # Find longest non-decreasing suffix
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1
        
        # If the entire array is already sorted
        if right == 0:
            return 0
        
        ans = right
        
        # Find the minimum length of subarray to remove
        while left < right and (left == 0 or arr[left - 1] <= arr[left]):
            while right < n and arr[left] > arr[right]:
                right += 1
            ans = min(ans, right - left - 1)
            left += 1
        
        return ans