class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size(), mx = 0;

        int dp[100001];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            dp[nums[i]] = 1;
            mx = max(mx, nums[i]);
        }

        int ans = -1;

        for(int i = 2; i <= mx; i++){
            if(dp[i] && (int)sqrt(i) * (int)sqrt(i) == i){
                dp[i] = dp[i] + dp[(int)sqrt(i)];
                ans = max(ans, dp[i]);
                cout<<i<<endl;
            }
        }

        if(ans == 1){
            return -1;
        }

        return ans;
    }
};
