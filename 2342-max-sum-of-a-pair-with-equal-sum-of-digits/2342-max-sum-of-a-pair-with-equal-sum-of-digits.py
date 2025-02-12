class Solution:
    def maximumSum(self, nums):
        mp = [-1] * 82  # Fixed size array
        ans = -1

        for num in nums:
            digit_sum = sum(int(d) for d in str(num))

            if mp[digit_sum] != -1:
                ans = max(ans, num + mp[digit_sum])

            mp[digit_sum] = max(mp[digit_sum], num)

        return ans