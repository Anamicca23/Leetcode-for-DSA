#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAXN = 100000;
int spf[MAXN + 1];

auto init = []() {
    memset(spf, -1, sizeof(spf));
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == -1) {
            spf[i] = i;
            for (int j = 2 * i; j <= MAXN; j += i)  // Fix overflow
                if (spf[j] == -1) spf[j] = i;
        }
    }
    return 0;
}();

void compute(vector<int>& nums, vector<int>& res, auto cmp, bool rev) {
    vector<int> stk;
    for (int i = rev ? nums.size() - 1 : 0, d = rev ? -1 : 1; 0 <= i && i < nums.size(); i += d) {
        while (!stk.empty() && cmp(nums[i], nums[stk.back()])) res[stk.back()] = i, stk.pop_back();
        stk.push_back(i);
    }
}

int distinct(int n) {
    int cnt = 0, last = 0;
    while (n > 1) {
        if (spf[n] > last) cnt++, last = spf[n];
        n /= spf[n];
    }
    return cnt;
}

long long mod_exp(long long base, int exp, long long mod) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = ans * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return ans;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> factors(n), nextGreater(n, n), prevGreater(n, -1);

        transform(nums.begin(), nums.end(), factors.begin(), distinct);
        compute(factors, nextGreater, greater<int>(), false);
        compute(factors, prevGreater, greater_equal<int>(), true);

        priority_queue<array<int, 2>> pq;
        for (int i = 0; i < n; i++) {
            long long cnt = 1LL * (i - prevGreater[i]) * (nextGreater[i] - i);
            pq.push({nums[i], static_cast<int>(min(cnt, 1000000000LL))});
        }

        long long ans = 1;
        while (!pq.empty() && k > 0) {
            auto [val, cnt] = pq.top(); pq.pop();
            int take = min(k, cnt);
            ans = ans * mod_exp(val, take, MOD) % MOD;
            k -= take;
        }
        return ans;
    }
};
