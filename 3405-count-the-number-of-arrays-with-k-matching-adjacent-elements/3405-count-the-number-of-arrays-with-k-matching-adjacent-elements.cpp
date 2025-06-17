const int mod = 1e9 + 7;
int fact[100000] = {0};
class Solution {
public:
    static void comp_fact(){
        if (fact[0] == 1)
            return;
        long long p = 1;
        fact[0] = 1;
        for (int i = 1; i < 100000; i++){
            p *= i;
            if (p >= mod) p %= mod;
            fact[i] = p;
        }
    }
    static inline long long modPow(long long x, unsigned exp, int Mod = mod){
        if (exp == 0) return 1;
        int bits = 31 - countl_zero(exp);
        bitset<32> B(exp);
        long long ans = x;
        for (int b = bits - 1; b >= 0; b--){
            ans = (ans * ans % Mod) * (B[b] ? x : 1) % Mod;
        }
        return ans;
    }
    static inline int Inv(int a, int b = mod){
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while (r1 != 0){
            int q = r0 / r1, rr = r1, xx = x1;
            r1= r0 - q * r1;
            x1 = x0 - q * x1;
            r0 = rr;
            x0 = xx;
        }
        if (x0 < 0)
            x0 += b;
        return x0;
    }
    static long long comb(int n, int k){
        return 1LL * fact[n] * Inv(fact[k]) % mod * Inv (fact[n - k]) % mod;
    }
    int countGoodArrays(int n, int m, int k) {
        comp_fact();
        return m * modPow(m - 1, n - k - 1) % mod * comb(n - 1, k) % mod;
    }
};