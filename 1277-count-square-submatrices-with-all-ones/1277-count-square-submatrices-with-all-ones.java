class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        // Memo table to store square sizes ending at each cell
        int[][] memo = new int[n][m];
        int res = 0;

        // Iterate over each cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is non-zero, calculate the largest square ending at this cell
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // Cells in the first row or column can only form 1x1 squares if they are 1
                        memo[i][j] = 1;
                    } else {
                        // Take the minimum of the three neighboring squares plus 1
                        memo[i][j] = 1 + Math.min(memo[i - 1][j], Math.min(memo[i][j - 1], memo[i - 1][j - 1]));
                    }
                    res += memo[i][j];
                }
            }
        }

        return res;
    }
}
