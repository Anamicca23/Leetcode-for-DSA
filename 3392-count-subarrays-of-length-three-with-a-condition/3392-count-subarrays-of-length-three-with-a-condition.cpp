class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count =0, n=nums.size();

        for(int i=0; i<n-2; i++){
            if((float)nums[i+1]/2 == (float)(nums[i]+nums[i+2])) count++;
        }

        return count;
    }
};