class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        vector<long long> dp(n + 1, 10e12);
        dp[0] = 0;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for (int i = 0; i < m; i++) {
            int position = factory[i][0];
            int limit = factory[i][1];
            while (limit--) {
                for (int j = n - 1; j >= 0; j--) {
                    dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j]);
                }
            }
        }
        return dp[n];
    }
};