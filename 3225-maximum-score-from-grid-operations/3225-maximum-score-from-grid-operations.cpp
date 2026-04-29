class Solution {
using ll = long long;
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) 
            return 0;
        vector<ll> dp0(n + 1, 0), dp1(n + 1, 0);

        for (int j = 1; j < n; j++) {
            vector<ll> new_dp0(n + 1, 0), new_dp1(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                ll prev = 0;
                ll curr = 0;
                for (int x = 0; x < i; x++) 
                    curr += grid[x][j];
                for (int y = 0; y <= n; y++) {
                    if (y > 0 && y <= i) {
                        curr -= grid[y - 1][j];
                    }
                    if (y > i) {
                        prev += grid[y - 1][j - 1];
                    }
                    new_dp0[y] = max({new_dp0[y], prev + dp0[i], dp1[i]});
                    new_dp1[y] = max({new_dp1[y], curr + dp1[i], curr + prev + dp0[i]});
                }
            }
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        return *max_element(dp1.begin(), dp1.end());
    }
};