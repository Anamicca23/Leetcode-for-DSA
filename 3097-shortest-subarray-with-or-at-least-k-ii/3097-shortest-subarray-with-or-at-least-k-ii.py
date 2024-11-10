class Solution:
    def __init__(self):
        self.bitts = []

    def answer(self, nums, idx, k):
        left, right = idx, len(nums) - 1
        ans = float('inf')
        
        while left <= right:
            mid = (left + right) // 2
            a = 0
            
            # Calculate OR for range [idx, mid] using bitwise counts
            for i in range(32):
                b = self.bitts[mid + 1][i] - self.bitts[idx][i]
                if b > 0:
                    a |= (1 << i)
            
            if a >= k:
                ans = min(ans, mid - idx + 1)
                right = mid - 1
            else:
                left = mid + 1
        
        return ans

    def minimumSubarrayLength(self, nums, k):
        n = len(nums)
        ans = float('inf')
        self.bitts = [[0] * 32 for _ in range(n + 1)]

        # Populate bitts with bit counts for prefix sums
        for i in range(n):
            for j in range(32):
                self.bitts[i + 1][j] = self.bitts[i][j] + ((nums[i] >> j) & 1)

        # Calculate minimum subarray length
        for i in range(n):
            temp = self.answer(nums, i, k)
            if temp != float('inf'):
                ans = min(ans, temp)
            else:
                break

        return -1 if ans == float('inf') else ans