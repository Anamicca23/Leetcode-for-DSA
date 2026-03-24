class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long pre = 1, suf = 1, mod = 12345;
        vector<vector<int>> A(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = pre * A[i][j] % mod;
                A[n - i - 1][m - j - 1] = suf * A[n - i - 1][m - j - 1] % mod;
                pre = pre * grid[i][j] % mod;
                suf = suf * grid[n - i - 1][m - j - 1] % mod;
            }
        }
        return A;
    }
};