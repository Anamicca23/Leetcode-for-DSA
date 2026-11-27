class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s 
        rows = [""] * numRows
        currentRow = 0
        step = 1
        for char in s:
            rows[currentRow]+=char
            if currentRow == 0:
                step = 1
            elif currentRow == numRows - 1:
                step = -1
            currentRow+=step
        return ''.join(rows)