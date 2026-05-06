class Solution {
    public char[][] rotateTheBox(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        for (int r = 0; r < rows; r++) {
            int p = 0;
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '.') {
                    char temp = grid[r][c];
                    grid[r][c] = grid[r][p];
                    grid[r][p] = temp;
                    p++;
                } else if (grid[r][c] == '*')
                    p = c + 1;
            }
        }
        
        char[][] res = new char[cols][rows];
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                res[c][rows - 1 - r] = grid[r][c];
                
        return res;
    }
}