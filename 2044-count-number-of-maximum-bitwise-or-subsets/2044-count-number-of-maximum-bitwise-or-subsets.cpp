class Solution {
public:
    int subsetcount(int idx,int curror, vector<int>& nums,int maxor, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(curror==maxor){
                return 1;
            }
            return 0;
        }
        if(dp[idx][curror]!=-1){
            return dp[idx][curror];
        }
        int included =  subsetcount(idx+1,curror | nums[idx],nums, maxor,dp);
        int notincluded = subsetcount(idx +1, curror, nums, maxor,dp);
        return dp[idx][curror] = included+notincluded;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int &n:nums) maxor |= n;
        vector<vector<int>>dp(nums.size()+1,vector<int>(maxor+1,-1));
        int curror=0;
        return  subsetcount(0,curror,nums,maxor,dp);
    }
};