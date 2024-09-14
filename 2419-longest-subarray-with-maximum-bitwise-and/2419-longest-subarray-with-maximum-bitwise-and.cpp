class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv=0,cnt=0,res=0;
        for(auto &x:nums){
            if(maxv<x){
                maxv=x;
                cnt=0;
                //res=0;
            }
            if(maxv==x){
                cnt++;
            }else{
                cnt=0;
            }
            res = max(cnt,res);
        }
        return res;
    }
    
};