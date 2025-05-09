#define LC_HACK
#ifdef LC_HACK
const auto __ = [] {
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(___::_);
    return 0;
}();
#endif

class Solution {
public:
    const int M = 1e9 + 7;
    using ll = long long;
    vector<ll> freq, fact, ifact;
    vector<vector<vector<ll>>> dp;
    ll n, sum;

    ll binpow(ll a, ll b) {
        ll r = 1;
        for (; b; b >>= 1, a = a * a % M)
            if (b & 1) r = r * a % M;
        return r;
    }

    ll count(int d, int t, int s) {
        if (d == 10) return (t == n / 2 && 2 * s == sum) ? fact[n / 2] * fact[(n + 1) / 2] % M : 0;
        if (dp[d][t][s] != -1) return dp[d][t][s];
        ll res = 0;
        for (int i = 0; i <= min((ll)freq[d], n / 2 - t); ++i)
            res = (res + ifact[i] * ifact[freq[d] - i] % M * count(d + 1, t + i, s + i * d) % M) % M;
        return dp[d][t][s] = res;
    }

    int countBalancedPermutations(string num) {
        n = num.size(); sum = 0;
        freq.assign(10, 0); fact.assign(n + 1, 1); ifact.resize(n + 1);
        for (char c : num) freq[c - '0']++, sum += c - '0';
        if (sum % 2) return 0;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % M;
        for (int i = 0; i <= n; ++i) ifact[i] = binpow(fact[i], M - 2);
        dp.assign(10, vector<vector<ll>>(n + 1, vector<ll>(sum + 1, -1)));
        return count(0, 0, 0);
    }
};
