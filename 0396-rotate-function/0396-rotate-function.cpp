class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long sum = 0;
        long F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long)i * nums[i];
        }

        long ans = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            ans = max(ans, F);
        }

        return (int)ans;
    }
};