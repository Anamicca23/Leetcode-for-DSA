from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        freq = defaultdict(int)
        left = 0
        pair_count = 0
        good_subarrays = 0

        for right in range(len(nums)):
            pair_count += freq[nums[right]]
            freq[nums[right]] += 1

            while pair_count >= k:
                good_subarrays += len(nums) - right
                freq[nums[left]] -= 1
                pair_count -= freq[nums[left]]
                left += 1

        return good_subarrays