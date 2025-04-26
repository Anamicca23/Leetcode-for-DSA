typedef long long int lli;
const lli inf = 1e6;

class Solution {
public:
	long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		lli ret = 0;
		int n = nums.size();

		vector<vector<lli>> v;
		vector<lli> temp;
		for (int i = 0; i < n; i++) {
			if (nums[i] < minK || nums[i] > maxK) {
				if (!temp.empty()) v.push_back(temp);
				temp.clear();
			} else {
				temp.push_back(nums[i]);
			}
		}
        if (!temp.empty()) v.push_back(temp);
		for (auto& it : v) {
			vector<lli> max_idx, min_idx;
            
			for (int i = 0; i < it.size(); i++) {
                // cout << i << endl;
				if (it[i] == maxK) {
					max_idx.push_back(i);
				}

				if (it[i] == minK) {
					min_idx.push_back(i);
				}
				if (!max_idx.empty() && !min_idx.empty()) {
					lli idx = min(max_idx.back(), min_idx.back());
                    // cout << idx << " -> "<< max_idx.back() << " " << min_idx.back() << endl;
					ret += idx + 1;
                    
				}
			}
            // cout << endl;
		}
		return ret;
	}
};
