class Solution {
    private static final int[][] TRANS = {
        {-1, 1, -1, 3},
        {0, -1, 2, -1},
        {3, 2, -1, -1},
        {1, -1, -1, 2},
        {-1, 0, 3, -1},
        {-1, -1, 1, 0}
    };
    private static final int[][] DIRS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private static final int[][] START = {{1, 3}, {0, 2}, {2, 3},
                                          {1, 2}, {0, 3}, {0, 1}};

    public boolean hasValidPath(int[][] grid) {
        if (grid[0][0] == 5) return false;
        if (grid[grid.length - 1][grid[0].length - 1] == 4) return false;

        int m = grid.length, n = grid[0].length;
        if (m == 1 && n == 1) return true;

        int[] s = START[grid[0][0] - 1];
        return check(grid, s[0]) || check(grid, s[1]);
    }

    private boolean check(int[][] grid, int di) {
        if (di == -1) return false;
        int m = grid.length, n = grid[0].length;
        int r = DIRS[di][0], c = DIRS[di][1];
        boolean[] visit = new boolean[m * n];

        while (r >= 0 && r < m && c >= 0 && c < n) {
            int cell = r * n + c;
            if (visit[cell]) return false;
            visit[cell] = true;

            di = TRANS[grid[r][c] - 1][di];
            if (di == -1) return false;
            if (r == m - 1 && c == n - 1) return true;

            r += DIRS[di][0];
            c += DIRS[di][1];
        }
        return false;
    }
}