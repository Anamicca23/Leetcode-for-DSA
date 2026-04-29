class Solution {
    public long maximumScore(int[][] grid) {
        int n = grid.length;
        if (n == 1) 
            return 0;
        long[] dp0 = new long[n + 1];
        long[] dp1 = new long[n + 1];
        for (int j = 1; j < n; j++) {
            long[] new_dp0 = new long[n + 1];
            long[] new_dp1 = new long[n + 1];
            for (int i = 0; i <= n; i++) {
                long prev = 0, curr = 0;
                for (int x = 0; x < i; x++)
                    curr += grid[x][j];
                for (int y = 0; y <= n; y++) {
                    if (y > 0 && y <= i)
                        curr -= grid[y - 1][j];
                    if (y > i)
                        prev += grid[y - 1][j - 1];
                    new_dp0[y] = Math.max(new_dp0[y], Math.max(prev + dp0[i], dp1[i]));
                    new_dp1[y] = Math.max(new_dp1[y], Math.max(curr + dp1[i], curr + prev + dp0[i]));
                }
            }
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        long res = 0;
        for (long v : dp1) 
            res = Math.max(res, v);
        return res;
    }
}