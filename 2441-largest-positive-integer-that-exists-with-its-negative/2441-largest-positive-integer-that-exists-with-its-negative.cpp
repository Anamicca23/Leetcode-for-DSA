class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool>exist(2001,false);
        int ans = -1;
        for(int it:nums){
            if(exist[-it+1000])ans=max(ans,abs(it));
            exist[it+1000]=true;
        }
        return ans;
    }
};