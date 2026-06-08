class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        ans = [0] * n
        left = 0
        right = n - 1
        i = 0
        j = n - 1
        while i < n:
            if nums[i] < pivot:
                ans[left] = nums[i]
                left += 1
            if nums[j] > pivot:
                ans[right] = nums[j]
                right -= 1
            i += 1
            j -= 1
        while left <= right:
            ans[left] = pivot
            left += 1

        return ans