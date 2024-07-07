class Solution:
    def findMaxK(self, nums):
        exist = [False] * 2001
        ans = -1
        for num in nums:
            if exist[-num + 1000]:
                ans = max(ans, abs(num))
            exist[num + 1000] = True
        return ans
