class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto &n:nums)sum+=n;
        long long lsum=0,rsum=0;
        int splitc=0;
        for(int i =0; i<n-1;i++){
            lsum +=nums[i],rsum = sum-lsum;
            if(lsum>=rsum)splitc++;
        }
        return splitc;
    }
};