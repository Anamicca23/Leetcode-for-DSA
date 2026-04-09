class Solution {
    static const int MOD = 1e9 + 7;
    long long modpow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;
        vector<vector<vector<pair<int,int>>>> events(B + 1);
        for (int k = 1; k <= B; k++) {
            events[k].resize(k);
        }
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (long long)nums[i] * v % MOD;
                }
            } else {
                int rem = l % k;
                int start = (l - rem) / k;
                int end   = (r - rem) / k;

                events[k][rem].push_back({start, v});
                int maxT = (n - 1 - rem) / k;
                if (end + 1 <= maxT) {
                    int inv = modpow(v, MOD - 2);
                    events[k][rem].push_back({end + 1, inv});
                }
            }
        }
        for (int k = 1; k <= B; k++) {
            for (int rem = 0; rem < k; rem++) {
                auto &ev = events[k][rem];
                if (ev.empty()) continue;
                sort(ev.begin(), ev.end());
                vector<pair<int,int>> comp;
                for (auto &p : ev) {
                    if (!comp.empty() && comp.back().first == p.first) {
                        comp.back().second = (long long)comp.back().second * p.second % MOD;
                    } else {
                        comp.push_back(p);
                    }
                }
                long long cur = 1;
                int ptr = 0;

                for (int t = 0, idx = rem; idx < n; t++, idx += k) {
                    while (ptr < comp.size() && comp[ptr].first == t) {
                        cur = cur * comp[ptr].second % MOD;
                        ptr++;
                    }
                    nums[idx] = nums[idx] * cur % MOD;
                }
            }
        }
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};