class Solution {
    public int maxProductPath(int[][] grid) {
        int MOD = (int)1e9 + 7;
        int m = grid.length, n = grid[0].length;

        long[][] min_dp = new long[m][n], max_dp = new long[m][n];
        min_dp[0][0] = grid[0][0]; 
        max_dp[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            max_dp[0][j] = max_dp[0][j-1] * grid[0][j];
            min_dp[0][j] = min_dp[0][j-1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
            min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long curr = grid[i][j];

                long max_top = max_dp[i-1][j], min_top = min_dp[i-1][j];
                long max_left = max_dp[i][j-1], min_left = min_dp[i][j-1];

                long[] candidates = {
                    max_top * curr,
                    min_top * curr,
                    max_left * curr,
                    min_left * curr
                };

                long max_val = candidates[0], min_val = candidates[0];

                for (int k = 1; k < 4; k++) {
                    max_val = Math.max(max_val, candidates[k]);
                    min_val = Math.min(min_val, candidates[k]);
                }

                max_dp[i][j] = max_val;
                min_dp[i][j] = min_val;
            }
        }

        long result = max_dp[m-1][n-1];

        if (result < 0) {
            return -1;
        }

        return (int)(result % MOD);
    }
}