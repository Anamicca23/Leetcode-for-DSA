class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [&](int x){
            return x%3!=0; });
    }
};