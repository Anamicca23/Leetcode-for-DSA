class Solution {
    private void markGuarded(int row, int col, int[][] grid) {
        // Mark cells in the up direction
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        // Mark cells in the down direction
        for (int i = row + 1; i < grid.length; i++) {
            if (grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        // Mark cells in the left direction
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 2 || grid[row][j] == 3) break;
            grid[row][j] = 1;
        }
        // Mark cells in the right direction
        for (int j = col + 1; j < grid[0].length; j++) {
            if (grid[row][j] == 2 || grid[row][j] == 3) break;
            grid[row][j] = 1;
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        // Mark guards as 2 in the grid
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        // Mark walls as 3 in the grid
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 3;
        }

        // Mark guarded cells
        for (int[] guard : guards) {
            markGuarded(guard[0], guard[1], grid);
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }
        return count;
    }
}
