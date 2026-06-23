class Solution {
public:
    static constexpr int MOD = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);
        for (int len = 2; len <= n; len++) {
            reverse(dp.begin(), dp.end());
            long long pref = 0;
            for (int i = 0; i < m; i++) {
                int old = dp[i];
                dp[i] = pref;
                pref = (pref + old) % MOD;
            }
        }
        long long ans = 0;
        for (int x : dp) {
            ans = (ans + x) % MOD;
        }
        return (ans * 2) % MOD;
    }
};