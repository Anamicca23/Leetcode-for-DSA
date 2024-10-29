class Solution {
public:
//dfs with memoization
    int n, m;
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> mem(n, vector<int>(m, -1));
        vector<int> direc = {-1, 0, 1};
        function<int(int, int)> dfs = [&](int row, int col) {
            if (mem[row][col] != -1) return mem[row][col];
            int moves = 0;
            for (int d : direc) {
                int nr = row + d, nc = col + 1;
                if (nr >= 0 && nr < n && nc < m && grid[nr][nc] > grid[row][col])
                    moves = max(moves, 1 + dfs(nr, nc));
            }
            return mem[row][col] = moves;
        };
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, dfs(i, 0));
        return res;
    }
};
