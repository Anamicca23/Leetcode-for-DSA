class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> val(n, pair<int, int>(0, 0));

        for (int i = 0; i < n; ++i) { 
            int num = nums[i], j = 0, ans = 0;
            if (num == 0) {
                ans = mapping[num];
            } else {
                while (num > 0) {
                    ans += pow(10, j) * mapping[num % 10];
                    num /= 10;
                    ++j;
                }
            }
            val[i].first = ans;
            val[i].second = i;
        }
        
        sort(val.begin(), val.end());
        vector<int> res(n);

        for (int i = 0; i < n; ++i) { 
            res[i] = nums[val[i].second];
        }

        return res;
    }
};