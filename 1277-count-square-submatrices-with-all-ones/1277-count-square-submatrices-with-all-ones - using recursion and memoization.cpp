class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (i >= n || j >= m) return 0;    
        if (matrix[i][j] == 0) return 0;   
        if (memo[i][j] != -1) return memo[i][j];

        int right = solve(i, j + 1, matrix);
        int diag = solve(i + 1, j + 1, matrix);
        int down = solve(i + 1, j, matrix);


        return memo[i][j] = 1 + min({right, diag, down});
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memo.assign(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    res += solve(i, j, matrix);
                }
            }
        }
        return res;
    }
};
