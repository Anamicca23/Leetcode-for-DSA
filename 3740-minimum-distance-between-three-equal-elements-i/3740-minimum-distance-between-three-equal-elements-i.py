class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        len_ = len(nums)
        last2 = [0] * len_
        res = 300

        for idx in range(len_):
            val = nums[idx] - 1
            pos = idx + 1
            pack = last2[val]
            old = pack & 255
            cur = pack >> 8

            last2[val] = cur | (pos << 8)

            if old:
                res = min(res, (pos - old) << 1)

        return -(res == 300) | res