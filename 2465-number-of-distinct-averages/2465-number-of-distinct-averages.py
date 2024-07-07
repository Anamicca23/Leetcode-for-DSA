class Solution:
    def distinctAverages(self, nums):
        st = set()
        nums.sort()
        n = len(nums)
        for i in range(n // 2):
            sum_ = nums[i] + nums[n - i - 1]
            st.add(sum_ / 2.0)
        return len(st)
