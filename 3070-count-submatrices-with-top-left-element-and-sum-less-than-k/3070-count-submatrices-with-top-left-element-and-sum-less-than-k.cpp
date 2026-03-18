class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> px(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                px[i+1][j+1] = grid[i][j] + px[i][j+1] + px[i+1][j] - px[i][j];
                if (px[i+1][j+1] <= k) ans++;
            }
        }
        return ans;
    }
};