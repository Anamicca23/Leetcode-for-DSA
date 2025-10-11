class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0LL;

        sort(power.begin(), power.end());
        vector<int> vals;
        vector<long long> earn;

        for (int i = 0; i < (int)power.size(); ) {
            int v = power[i];
            long long s = 0;
            while (i < (int)power.size() && power[i] == v) {
                s += v;
                ++i;
            }
            vals.push_back(v);
            earn.push_back(s);
        }

        int n = (int)vals.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int nextIdx = int(lower_bound(vals.begin(), vals.end(), vals[i] + 3) - vals.begin());
            long long take = earn[i] + dp[nextIdx];
            long long skip = dp[i + 1];
            dp[i] = max(skip, take);
        }
        return dp[0];
    }
};