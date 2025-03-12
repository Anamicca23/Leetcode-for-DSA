from typing import List

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        nos, pos = 0, 0
        
        for num in nums: 
            if num < 0:
                nos += 1
            elif num > 0:  
                pos += 1
        
        return max(nos, pos) 
