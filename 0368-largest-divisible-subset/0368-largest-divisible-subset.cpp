class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxLen = 0, last = 0;
        vector<int> dp(n, 1), par(n);
        iota(par.begin(), par.end(), 0);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1, par[i] = j;

        for (int i = 0; i < n; ++i)
            if (dp[i] > maxLen) maxLen = dp[i], last = i;

        vector<int> res;
        while (par[last] != last) res.push_back(nums[last]), last = par[last];
        res.push_back(nums[last]);
        reverse(res.begin(), res.end());
        return res;
    }
};
