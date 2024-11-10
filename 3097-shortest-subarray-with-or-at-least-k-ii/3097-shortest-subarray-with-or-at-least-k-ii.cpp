class Solution {
    vector<vector<int>> bitts;
    int answer(vector<int>& nums, int idx, int k) {
        int left = idx, right = nums.size() - 1, ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            int a = 0;
            for (int i = 0; i < 32; i++) {
                int b = (bitts[mid + 1][i] - bitts[idx][i]);
                if (b)
                    a += (1 << i);
            }
            if (a >= k) {
                ans = min(ans, mid - idx + 1);
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return ans;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        bitts.resize(n + 1, vector<int>(32, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 32; j++)
                bitts[i + 1][j] = bitts[i][j] + ((nums[i] >> j) & 1);

        for (int i = 0; i < n; i++) {
            int temp = answer(nums, i, k);
            if (temp != INT_MAX)
                ans = min(ans, temp);
            else
                break;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};