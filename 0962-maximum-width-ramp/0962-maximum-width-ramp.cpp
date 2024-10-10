class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int mwramp=0;
        vector<int>rmax(n);
        rmax[n-1]=nums[n-1];
        for(int i =n-2; i>=0; i--){
           rmax[i]= max(rmax[i+1],nums[i]);
        }
        int i=0,j=0;
        while(j<n){
            while(i<j and nums[i]>rmax[j]){i++;}
            mwramp = max(mwramp,j-i);
            j++;
        }
        return mwramp;
    }
};