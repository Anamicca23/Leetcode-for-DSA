class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, res = 0;
        bitset<2001> total, curr;
        vector<int> freq(2001);

        for (int x : nums) total.set(x);

        while (r < n) {
            curr.set(nums[r]);
            freq[nums[r]]++;
            while (curr == total) {
                res += n - r;
                if (--freq[nums[l]] == 0) curr.reset(nums[l]);
                l++;
            }
            r++;
        }
        return res;
    }
};
