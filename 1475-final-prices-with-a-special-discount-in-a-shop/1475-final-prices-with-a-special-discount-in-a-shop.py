from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        result = prices[:]  # Make a copy of the prices array
        stack = []  # Use a list as a stack

        for i in range(len(prices)):
            while stack and prices[i] <= prices[stack[-1]]:
                result[stack.pop()] -= prices[i]
            stack.append(i)
        
        return result
