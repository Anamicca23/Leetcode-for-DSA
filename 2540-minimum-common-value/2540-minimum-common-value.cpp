
typedef long long int lli;

class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		set<int> all(nums1.begin(), nums1.end())      ;
		sort(nums2.begin(), nums2.end());
		for (auto& it : nums2)if (all.count(it)) return it;
		return -1;
	}
};
