class Solution {
    int mooresVotingAlgo(vector<int>& nums) {
        int maj = nums[0], freq = 1;
        for (int i = 1; i < nums.size(); ++i) {
            freq += (nums[i] == maj) ? 1 : -1;
            if (freq == 0) maj = nums[i], freq = 1;
        }
        return maj;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), maj = mooresVotingAlgo(nums), cnt = 0;
        for (int x : nums) cnt += (x == maj);

        int pre = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == maj) pre++, cnt--;
            if (pre > (i + 1) / 2 && cnt > (n - i - 1) / 2) return i;
        }
        return -1;
    }
};
