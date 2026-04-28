class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for (auto &row : grid) {
                for (int k : row) {
                    nums.push_back(k);
                }
            }
            sort(nums.begin(), nums.end()); 
            int target = nums[nums.size() / 2];
            long long totalOperations = 0;
            for (int k : nums) {
                int temp = abs(k - target);
                if (temp % x != 0) return -1;
                totalOperations += temp / x; 
            }
            return totalOperations;
        }
    };