class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = 36;
        for (auto& n : nums)
            res = min(res, n - 9 * ((n/10) + (n/100) + (n/1000) + (n/10000)));
        return res;
    }
};