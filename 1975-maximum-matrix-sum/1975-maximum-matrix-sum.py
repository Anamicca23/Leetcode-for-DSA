from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        total_sum = 0
        negative_count = 0
        abs_min = float('inf')
        
        for row in matrix:
            for value in row:
                total_sum += abs(value)
                if value < 0:
                    negative_count += 1
                abs_min = min(abs_min, abs(value))
        
        # If there are an odd number of negative values, subtract twice the smallest absolute value
        return total_sum - 2 * abs_min if negative_count % 2 == 1 else total_sum