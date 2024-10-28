import math

class Solution:
    def longestSquareStreak(self, nums):
        dp = [0] * 100001
        mx = 0
        
        for num in nums:
            dp[num] = 1
            mx = max(mx, num)
        
        ans = -1

        for i in range(2, mx + 1):
            root = int(math.sqrt(i))
            if dp[i] and root * root == i:
                dp[i] += dp[root]
                ans = max(ans, dp[i])
        
        return -1 if ans == 1 else ans
