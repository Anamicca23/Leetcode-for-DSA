class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1; // edge case
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        d[0][0] = 0;
        while (!pq.empty()) {
            auto [v, i, j] = pq.top();
            pq.pop();
            if (i == m - 1 && j == n - 1)
                return v;
            int dir[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int ii = i + dir[k], jj = j + dir[k + 1];
                if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                    int diff = grid[ii][jj] - v;
                    if (diff < 0)
                        diff = 0;
                    else if (diff & 1)
                        diff = diff / 2 * 2;
                    int vv = v + 1 + diff;
                    if (d[ii][jj] > vv) {
                        d[ii][jj] = vv;
                        pq.push({vv, ii, jj});
                    }
                }
            }
        }
        return -1;
    }
};
void FastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
}