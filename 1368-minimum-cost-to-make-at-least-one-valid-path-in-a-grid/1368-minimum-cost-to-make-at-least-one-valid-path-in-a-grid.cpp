class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), d[n][m];
        memset(d, 0x3f, sizeof(d)); // Set all distances to a large value
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        deque<pair<int, int>> q{{0, 0}};
        d[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i], w = (i + 1 != g[x][y]);
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && d[nx][ny] > d[x][y] + w) {
                    d[nx][ny] = d[x][y] + w;
                    if (w) q.push_back({nx, ny});
                    else q.push_front({nx, ny});
                }
            }
        }
        return d[n-1][m-1];
    }
};