class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector <int> dp(t + 26);
        for (int i = 0; i < 26; i++)
            dp[i] = 1;
        for (int i = 26; i < t + 26; i++)
            dp[i] = (dp[i - 26] + dp[i - 25]) % mod;
        int ans = 0;
        for (char ch : s) 
            ans = (ans + dp[ch - 'a' + t]) % mod;
        return ans;
    }
};