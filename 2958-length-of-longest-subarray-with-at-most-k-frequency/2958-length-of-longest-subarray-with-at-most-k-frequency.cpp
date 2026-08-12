class Solution {
public:
	int maxSubarrayLength(vector<int>& nums, int k) {
		int ret = 0;
		map<int, int> freq;
		int n = nums.size();
		for (int i = 0, j = 0; i < n; i++) {
			freq[nums[i]]++;
			while (j <= i && freq[nums[i]] > k) {
				freq[nums[j]]--;
				j++;
			}
			ret = max(ret, i - j + 1);
		}
		return ret;
	}
};