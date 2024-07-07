class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int sum = nums[i] + nums[n - i - 1];
            st.insert(static_cast<double>(sum) / 2.0);
        }
        return st.size();
    }
};
