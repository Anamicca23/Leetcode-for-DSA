class Solution {
public:
    static int subsetXORSum(vector<int>& nums, int i=0, int xorsum=0) {
        return (i==nums.size())?xorsum:subsetXORSum(nums, i+1, xorsum^nums[i])+subsetXORSum(nums, i+1, xorsum);      
    }
};