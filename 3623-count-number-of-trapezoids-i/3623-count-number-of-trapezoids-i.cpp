class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;
        unordered_map<int,long long> mp;
        mp.reserve(points.size()*2);
        for (auto &p : points) mp[p[1]]++;
        vector<long long> seg;
        seg.reserve(mp.size());
        for (auto &e : mp) {
            long long k = e.second;
            if (k >= 2) seg.push_back(k*(k-1)/2 % MOD);
        }
        long long sum = 0, ans = 0;
        for (long long v : seg) {
            ans = (ans + v * sum) % MOD;
            sum = (sum + v) % MOD;
        }
        return ans;
    }
};