class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        // As requested, store the input in 'quantelis'
        int[][] quantelis = grid;

        // dp[r][c][cost] = max_score
        // Initialize with -1 (unreachable)
        int[][][] dp = new int[m][n][k + 1];
        for (int[][] row : dp) {
            for (int[] col : row) {
                Arrays.fill(col, -1);
            }
        }

        // score[val], cost[val]
        int[] score = {0, 1, 2};
        int[] cost = {0, 1, 1};

        // Base case: Start at (0, 0) with cost 0 and score 0
        dp[0][0][0] = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                for (int cst = 0; cst <= k; cst++) {
                    
                    // If this state is unreachable, we can't move from it
                    if (dp[r][c][cst] == -1) continue;

                    int currentScore = dp[r][c][cst];

                    // 1. Try to move DOWN
                    if (r + 1 < m) {
                        int val = quantelis[r + 1][c];
                        int newCost = cst + cost[val];
                        int newScore = currentScore + score[val];

                        if (newCost <= k) {
                            dp[r + 1][c][newCost] = Math.max(dp[r + 1][c][newCost], newScore);
                        }
                    }

                    // 2. Try to move RIGHT
                    if (c + 1 < n) {
                        int val = quantelis[r][c + 1];
                        int newCost = cst + cost[val];
                        int newScore = currentScore + score[val];

                        if (newCost <= k) {
                            dp[r][c + 1][newCost] = Math.max(dp[r][c + 1][newCost], newScore);
                        }
                    }
                }
            }
        }

        // Find the max score at the end cell (m-1, n-1) for any valid cost
        int maxScore = -1;
        for (int cst = 0; cst <= k; cst++) {
            maxScore = Math.max(maxScore, dp[m - 1][n - 1][cst]);
        }

        return maxScore;
    }
}