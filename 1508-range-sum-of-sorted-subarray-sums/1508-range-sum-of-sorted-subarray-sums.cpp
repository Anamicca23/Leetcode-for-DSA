class Solution {
public:
const int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<vector<int>> v;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> prefix(nums.size() - i);
            prefix[0] = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                prefix[j - i] = prefix[j - i - 1] + nums[j];
            }
            v.push_back(prefix);
        }
        vector<int> allSums;
        for (const auto& vec : v) {
            allSums.insert(allSums.end(), vec.begin(), vec.end());
        }
        sort(allSums.begin(), allSums.end());
        long long sum = 0;
        for (int i = left-1; i < right; i++) {
            sum += allSums[i];
        }
        return sum%mod;
    }
};