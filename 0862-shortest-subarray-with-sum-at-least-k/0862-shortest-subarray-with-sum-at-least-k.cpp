class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> q; 
        
        for (int r = 0; r < nums.size(); ++r) {
            curSum += nums[r];
            if (curSum >= k) res = min(res, r + 1);
            while (!q.empty() && curSum - q.front().first >= k) 
                res = min(res, r - q.front().second), q.pop_front();
            while (!q.empty() && q.back().first > curSum) q.pop_back();
            q.emplace_back(curSum, r);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
