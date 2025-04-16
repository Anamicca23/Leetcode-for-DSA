class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int right = 0;
        int left = 0;
        long long res = 0;

        while (right < n) {
            k -= m[nums[right++]]++;

            while (k <= 0)
                k += --m[nums[left++]];

            res += left;
        }

        return res;
    }
};