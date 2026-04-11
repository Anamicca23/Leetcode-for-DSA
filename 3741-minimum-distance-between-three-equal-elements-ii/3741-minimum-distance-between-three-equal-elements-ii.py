class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        min_length = len(nums) + 1

        last_indices = [-1] * min_length
        second_to_last_indices = [-1] * min_length

        min_dist = math.inf
        for i, num in enumerate(nums):
            if second_to_last_indices[num] != -1:
                dist = i - second_to_last_indices[num]
                if min_dist > dist:
                    min_dist = dist
            second_to_last_indices[num], last_indices[num] = last_indices[num], i
        if min_dist == math.inf:
            return -1
        return 2 * min_dist