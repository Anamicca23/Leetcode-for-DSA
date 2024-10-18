class Solution {
public:
    int subsetcount(int idx,int curror, vector<int>& nums,int maxor){
        if(idx == nums.size()){
            if(curror==maxor){
                return 1;
            }
            return 0;
        }
        int included =  subsetcount(idx+1,curror | nums[idx],nums, maxor);
        int notincluded = subsetcount(idx +1, curror, nums, maxor);
        return included+notincluded;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int &n:nums) maxor |= n;
        int curror=0;
        return subsetcount(0,curror,nums,maxor);
    }
};
