class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        partial_sum(nums.begin(), nums.end(), nums.begin(),
        [prev=(nums[0]&1)](int sum, int x) mutable{
            sum+=((x&1)==prev);
            prev=(x&1);
            return sum;
        });
        int m=queries.size(), i=0;
        vector<bool> ans(m, 0);
        for (auto& q: queries)
            ans[i++]=(nums[q[0]]==nums[q[1]]);
        return ans;
    }
};