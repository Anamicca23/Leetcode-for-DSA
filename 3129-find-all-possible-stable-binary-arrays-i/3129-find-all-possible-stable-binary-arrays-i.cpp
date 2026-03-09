class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = min(zero, limit); i >= 0; i--)
            dp[i][0][0] = 1;
        for (int j = min(one, limit); j >= 0; j--)
            dp[0][j][1] = 1;
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp[i][j][0] = (0LL + dp[i - 1][j][0] + dp[i - 1][j][1]
                                - (i - 1 - limit >= 0 ? dp[i - 1 - limit][j][1] : 0)
                                + MOD) % MOD;
                dp[i][j][1] = (0LL + dp[i][j - 1][0] + dp[i][j - 1][1]
                                - (j - 1 - limit >= 0 ? dp[i][j - 1 - limit][0] : 0)
                                + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};