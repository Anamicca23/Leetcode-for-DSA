class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int n = grid.length, m = grid[0].length, A[][] = new int[n][m];
        long pre = 1, suf = 1, mod = 12345;
        for (int i = 0; i < n; i++) {
            if (i <= n - i - 1) {
                Arrays.fill(A[i], 1);
                Arrays.fill(A[n - i - 1], 1);
            }
            for (int j = 0; j < m; j++) {
                A[i][j] = (int)(pre * A[i][j] % mod);
                A[n - i - 1][m - j - 1] = (int)(suf * A[n - i - 1][m - j - 1] % mod);
                pre = pre * grid[i][j] % mod;
                suf = suf * grid[n - i - 1][m - j - 1] % mod;
            }
        }
        return A;
    }
}