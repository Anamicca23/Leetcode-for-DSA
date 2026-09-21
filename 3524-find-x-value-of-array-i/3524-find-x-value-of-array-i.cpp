int prevCount[100], currCount[100];

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        const int n = nums.size();
        
        if (k == 1) 
            return {1LL * n * (n + 1) / 2};
            
        vector<long long> ans(k, 0);
        memset(prevCount, 0, sizeof(int) * k);
        
        for (int x : nums) {
            const int r = x % k;
            memset(currCount, 0, sizeof(int) * k);
            ans[r]++;
            
            for (int j = 0; j < k; j++) {
                const int prod = (1LL * j * r) % k;
                currCount[prod] += prevCount[j];
                ans[prod] += prevCount[j];
            }
            
            currCount[r]++;
            memcpy(prevCount, currCount, sizeof(int) * k);
        }
        
        return ans;
    }
};