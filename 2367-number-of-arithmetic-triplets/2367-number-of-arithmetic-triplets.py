from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        count = 0
        for num in arr:
            if num % 2 != 0:
                count += 1
                if count == 3:
                    return True
            else:
                count = 0
        return False

    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        num_set = set(nums)
        count = 0
        for num in nums:
            if num + diff in num_set and num + 2 * diff in num_set:
                count += 1
        return count