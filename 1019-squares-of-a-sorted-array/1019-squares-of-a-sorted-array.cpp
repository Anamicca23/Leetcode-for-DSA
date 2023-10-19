class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n = nums.size();
       vector<int> ans(n);
        int start = 0, end = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[start]) < abs(nums[end])) {
                ans[i] = nums[end] * nums[end];
                end--;
            } else {
                ans[i] = nums[start] * nums[start];
                start++;
            }
        }

        return ans;
    }
};