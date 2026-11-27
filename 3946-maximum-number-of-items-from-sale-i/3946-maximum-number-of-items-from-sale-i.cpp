class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = INT_MAX;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mn = min(mn, items[i][1]);
            mx = max(mx, items[i][0]);
        }
        vector<int> freq(mx + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
        }
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int cnt = 0;
            for (int j = factor; j <= mx; j += factor) {
                cnt += freq[j];
            }
            val[i] = cnt;
        }
        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            for (int b = budget; b >= price; b--) {
                if (dp[b - price] != -1e9) {
                    dp[b] = max(dp[b], dp[b - price] + val[i]);
                }
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            if (dp[b] != -1e9) {
                ans = max(ans, dp[b] + (budget - b) / mn);
            }
        }
        return ans;
    }
};