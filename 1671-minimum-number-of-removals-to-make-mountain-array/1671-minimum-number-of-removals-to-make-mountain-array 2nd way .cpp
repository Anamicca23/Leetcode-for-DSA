class Solution {
public:
    vector<int> getLISLengths(vector<int>& v) {
        vector<int> lisLen(v.size(), 1), lis = {v[0]};
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > lis.back()) lis.push_back(v[i]);
            else lis[lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin()] = v[i];
            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), minRemovals = INT_MAX;
        vector<int> lis = getLISLengths(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lds = getLISLengths(nums);
        reverse(lds.begin(), lds.end());

        for (int i = 0; i < n; ++i) 
            if (lis[i] > 1 && lds[i] > 1) 
                minRemovals = min(minRemovals, n - lis[i] - lds[i] + 1);

        return minRemovals;
    }
};
