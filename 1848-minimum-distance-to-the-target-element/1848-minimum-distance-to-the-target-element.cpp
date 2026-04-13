class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int i1 = start + i;
            int i2 = start - i;
            if(i1 >=0 && i1 < n && nums[i1] == target){
                ans = i;
                break;
            }
            if(i2 >=0 && i2 < n && nums[i2] == target){
                ans = i;
                break;
            }
        }
        return ans;
    }
};