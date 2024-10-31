class Solution {
public:
    vector<vector<int>> res;

    void twosum(vector<int>& nums, int targ, int i, int j) {
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < targ) {
                i++;
            } else if (sum > targ) {
                j--;
            } else {
                res.push_back({-targ, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates
            int targ = -nums[i];
            twosum(nums, targ, i + 1, n - 1);
        }
        return res;
    }
};
