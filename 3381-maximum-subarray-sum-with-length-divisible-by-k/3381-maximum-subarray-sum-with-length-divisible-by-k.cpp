class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);

        long long prefix = 0;
        long long answer = LLONG_MIN;

        minPrefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int mod = (i + 1) % k;

            if (minPrefix[mod] != LLONG_MAX) {
                answer = max(answer, prefix - minPrefix[mod]);
            }

            minPrefix[mod] = min(minPrefix[mod], prefix);
        }

        return answer;
    }
};