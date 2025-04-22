const int mod = 1e9+7, N = 10015;
bitset<101> sieve;
array<int, 25> prime;

static constexpr void sieve100() {
    if (sieve[0]) return;
    sieve[0] = sieve[1] = 1;
    int sz = 0;
    for (int p = 2; p < 10; ++p)
        if (!sieve[p]) {
            prime[sz++] = p;
            for (int j = p*p; j < 100; j += p) sieve[j] = 1;
        }
    for (int i = 11; i < 100; i += 2)
        if (!sieve[i]) prime[sz++] = i;
}

int C[N][15]{};

static constexpr void Pascal() {
    if (C[0][0]) return;
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= min(14, i); ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
}

unsigned dp[N];

static constexpr long long factor(int x, const int n) {
    if (dp[x]) return dp[x];
    if (x <= 1) return dp[x] = 1;
    if (x < 100 && !sieve[x]) return dp[x] = n;

    long long cnt = 1;
    int x0 = x;
    for (int p : prime) {
        if (p * p > x0) break;
        if (x0 % p) continue;
        int exp = 0;
        while (x0 % p == 0) x0 /= p, ++exp;
        cnt = cnt * C[n - 1 + exp][exp] % mod;
        if (dp[x0]) return dp[x] = cnt * dp[x0] % mod;
    }
    if (x0 > 1) cnt = cnt * n % mod;
    return dp[x] = cnt;
}

class Solution {
public:
    static int idealArrays(int n, int maxValue) {
        sieve100();
        Pascal();
        memset(dp, 0, (maxValue + 1) * sizeof(unsigned));
        long long ans = 0;
        for (int x = 1; x <= maxValue; ++x)
            ans = (ans + factor(x, n)) % mod;
        return ans;
    }
};
