class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a1 =0,a2=0;
        int ans =0;
        for(int i =0;i< nums.size() ;i++){
            a1 += nums[i];
            if(a1<0){
                a1 =0;
            }
            a2 += nums[i];
            if(a2>0){
                a2 =0;
            }
            ans = max(ans ,max(a1,abs (a2)));
        }
        return ans; 
    }
};