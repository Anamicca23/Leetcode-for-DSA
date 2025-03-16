class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = n;
        for (int i=0; i<n; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};