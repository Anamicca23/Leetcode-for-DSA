class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = n - 1, j= m - 1; 
        vector<int> dp(n + 1, 0); 
        for(; i >= 0; i--) {
            if(j >= 0 && s[i] == t[j]) {
                dp[i] = dp[i + 1] + 1; 
                j--; 
            } else dp[i] = dp[i + 1]; 
        }
        vector<int> ans; 
        j = 0; 
        bool flag = true; 
        for(int i = 0; i < n && j < m; i++) {
            int rem = m - j - 1;
            if( s[i] == t[j]) {
                ans.push_back(i);  
                j++; 
            } else if(flag && dp[i + 1] >= rem) {
                ans.push_back(i); 
                j++; 
                flag = false; 
            }
        }
        if (j == m) return ans; 
        return {}; 
    }
};