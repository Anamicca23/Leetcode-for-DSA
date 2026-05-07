class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            res.push_back(max(res.back(), nums[i]));
        }

        int min_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (res[i] > nums[min_idx]) {
                res[i] = res[min_idx];
            }
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
        }
        return res;
    }
};