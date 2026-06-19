class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_height = 0
        curr_height = 0
        for g in gain:
            curr_height += g
            max_height = max(max_height, curr_height)
        return max_height