class Solution {
    public int maxPathScore(int[][] grid, int K) {
        if (minPathSum(grid) > K) {
            return -1;
        }
        int m = grid.length;
        int n = grid[0].length;
        K = Math.min(K, m + n - 2);
        int[][] f = new int[n + 1][K + 2];
        for (int[] row : f) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        f[1][1] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                for (int k = Math.min(K, i + j); k >= 0; k--) { 
                    int newK = x > 0 ? k - 1 : k;
                    f[j + 1][k + 1] = Math.max(f[j + 1][newK + 1], f[j][newK + 1]) + x;
                }
            }
        }
        int ans = 0;
        for (int x : f[n]) {
            ans = Math.max(ans, x);
        }
        return ans;
    }
    private int minPathSum(int[][] grid) {
        int n = grid[0].length;
        int[] f = new int[n + 1];
        Arrays.fill(f, Integer.MAX_VALUE);
        f[1] = 0;
        for (int[] row : grid) {
            for (int j = 0; j < n; j++) {
                f[j + 1] = Math.min(f[j], f[j + 1]) + Math.min(row[j], 1); 
            }
        }
        return f[n];
    }
}