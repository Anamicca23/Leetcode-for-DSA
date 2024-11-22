from collections import Counter

class Solution:
    def maxEqualRowsAfterFlips(self, matrix):
        freq = Counter()
        for row in matrix:
            first_val = row[0]
            pattern = ''.join('A' if val == first_val else 'B' for val in row)
            freq[pattern] += 1
        return max(freq.values())
