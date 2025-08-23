class Solution {
    int[][] ruc;
    int m, n;

    public int minimumSum(int[][] grid) {
        m = grid.length; n = grid[0].length;
        ruc = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ruc[i + 1][j + 1] = ruc[i][j + 1] + ruc[i + 1][j] - ruc[i][j] + grid[i][j];

        int ans = m * n;
        for (int i = 0; i < m - 2; i++)
            for (int j = i + 1; j < m - 1; j++)
                ans = Math.min(ans, 
                    minArea(0, 0, i, n - 1)
                  + minArea(i + 1, 0, j, n - 1)
                  + minArea(j + 1, 0, m - 1, n - 1));
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
                ans = Math.min(ans,
                    minArea(0, 0, m - 1, i)
                  + minArea(0, i + 1, m - 1, j)
                  + minArea(0, j + 1, m - 1, n - 1));
        for (int i = 0; i < m - 1; i++) {
            int top = minArea(0, 0, i, n - 1);
            int bottom = minArea(i + 1, 0, m - 1, n - 1);
            for (int j = 0; j < n - 1; j++) {
                int bl = minArea(i + 1, 0, m - 1, j);
                int br = minArea(i + 1, j + 1, m - 1, n - 1);
                ans = Math.min(ans, top + bl + br);
                int tl = minArea(0, 0, i, j);
                int tr = minArea(0, j + 1, i, n - 1);
                ans = Math.min(ans, bottom + tl + tr);
            }
        }
        for (int j = 0; j < n - 1; j++) {
            int left = minArea(0, 0, m - 1, j);
            int right = minArea(0, j + 1, m - 1, n - 1);
            for (int i = 0; i < m - 1; i++) {
                int tl = minArea(0, j + 1, i, n - 1);
                int bl = minArea(i + 1, j + 1, m - 1, n - 1);
                ans = Math.min(ans, left + tl + bl);
                int tr = minArea(0, 0, i, j);
                int br = minArea(i + 1, 0, m - 1, j);
                ans = Math.min(ans, right + tr + br);
            }
        }

        return ans;
    }
    int minArea(int r0, int c0, int r1, int c1) {
        int total = ruc[r1 + 1][c1 + 1] - ruc[r0][c1 + 1] - ruc[r1 + 1][c0] + ruc[r0][c0];
        if (total == 0) return 0;
        int rl = r0, rr = r1, cl = c0, cr = c1;
        while (ruc[rl + 1][c1 + 1] - ruc[rl][c1 + 1] - ruc[rl + 1][c0] + ruc[rl][c0] == 0) rl++;
        while (ruc[r1 + 1][c1 + 1] - ruc[rr][c1 + 1] - ruc[r1 + 1][c0] + ruc[rr][c0] == 0) rr--;
        while (ruc[r1 + 1][cl + 1] - ruc[r0][cl + 1] - ruc[r1 + 1][cl] + ruc[r0][cl] == 0) cl++;
        while (ruc[r1 + 1][c1 + 1] - ruc[r0][c1 + 1] - ruc[r1 + 1][cr] + ruc[r0][cr] == 0) cr--;
        return (rr - rl + 1) * (cr - cl + 1);
    }
}