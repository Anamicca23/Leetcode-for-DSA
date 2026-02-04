class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long res = -2e18;
        for (int i = 1; i < n - 2; ) {
            int a = i, b = i;
            long long net = nums[a];
            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[++b];
            }
            if (b == a) { i++; continue; }
            int c = b;
            long long left = 0, right = 0, lx = -2e18, rx = -2e18;
            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[--a];
                lx = max(lx, left);
            }
            if (a == i) { i++; continue; }
            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[++b];
                rx = max(rx, right);
            }
            if (b == c) { i++; continue; }
            res = max(res, lx + rx + net);
            i = b;
        }
        return res;
    }
};