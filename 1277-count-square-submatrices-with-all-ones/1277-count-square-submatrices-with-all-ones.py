class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])

        # Memo table to store square sizes ending at each cell
        memo = [[0] * m for _ in range(n)]
        res = 0

        # Iterate over each cell in the matrix
        for i in range(n):
            for j in range(m):
                # If the cell is non-zero, calculate the largest square ending at this cell
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        # Cells in the first row or column can only form 1x1 squares if they are 1
                        memo[i][j] = 1
                    else:
                        # Take the minimum of the three neighboring squares plus 1
                        memo[i][j] = 1 + min(memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1])
                    res += memo[i][j]

        return res
