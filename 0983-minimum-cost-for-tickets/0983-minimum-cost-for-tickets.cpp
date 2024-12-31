class Solution {
public:
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.assign(n, -1);
        function<int(int)> f = [&](int i) -> int {
            if (i >= n) return 0;
            if (dp[i] != -1) return dp[i];
            int ans = INT_MAX, j = i;
            for (int d : {1, 7, 30}) {
                while (j < n && days[j] < days[i] + d) j++;
                ans = min(ans, f(j) + costs[d == 1 ? 0 : d == 7 ? 1 : 2]);
            }
            return dp[i] = ans;
        };
        return f(0);
    }
};
