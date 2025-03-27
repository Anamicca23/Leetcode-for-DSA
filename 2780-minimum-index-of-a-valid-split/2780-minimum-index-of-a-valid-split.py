class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        cnt = 0
        domi_num = 0
        for num in nums:
            if cnt == 0:
                domi_num = num
            if domi_num == num:
                cnt += 1
            else:
                cnt -= 1
        n = len(nums)
        tot = nums.count(domi_num)
        if n == tot * 2 - 1:
            return -1
        cnt = 0
        for i, num in enumerate(nums):
            if num == domi_num:
                cnt += 1
            if cnt * 2 > i + 1 and (tot - cnt) * 2 > n - i - 1:
                return i
        return -1