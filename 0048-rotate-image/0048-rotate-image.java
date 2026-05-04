class Solution {
    public void rotate(int[][] matrix) {
        int maxRows = matrix.length - 1;
        int minRows = 0;
        int maxCols = matrix[0].length - 1;
        int minCols = 0;
        while(minRows < maxRows && minCols < maxCols) {
            for(int col = minCols, row = minRows; col < maxCols; col++) {
                int value = matrix[row][col];
                int newRow = col;
                int newCol = maxCols;
                int temp = matrix[newRow][newCol];
                matrix[newRow][newCol] = value;
                value = temp;

                newCol = maxCols - newRow + minCols;
                newRow = maxRows;
                temp = matrix[newRow][newCol];
                matrix[newRow][newCol] = value;
                value = temp;

                newRow = newCol;
                newCol = minCols;
                temp = matrix[newRow][newCol];
                matrix[newRow][newCol] = value;
                value = temp;

                matrix[row][col] = value;
            }
            minRows++;
            maxRows--;
            minCols++;
            maxCols--;
        }
    }
}