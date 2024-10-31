class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int m = robot.size(), n = factory.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[m][n] = 0;  // Set the base case for no robots left

        for (int j = n - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> q = {{m, 0}};
            for (int i = m - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);
                
                while (!q.empty() && q.front().first > i + factory[j][1]) q.pop_front();
                if (!q.empty() && q.front().second != LLONG_MAX)
                    dp[i][j] = min(dp[i][j], q.front().second + prefix);
                
                while (!q.empty() && q.back().second >= dp[i][j + 1] - prefix) q.pop_back();
                q.push_back({i, dp[i][j + 1] == LLONG_MAX ? LLONG_MAX : dp[i][j + 1] - prefix});
            }
        }

        return dp[0][0];
    }
};
