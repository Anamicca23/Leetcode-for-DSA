constexpr unsigned MOD = 1000000007;

const auto add = [] (unsigned lhs, unsigned rhs) {
    const unsigned ans = lhs + rhs;
    return ans < MOD ? ans: ans - MOD;
};

const auto sub = [] (unsigned lhs, unsigned rhs) {
    const unsigned ans = lhs - rhs;
    return ans < MOD ? ans: ans + MOD;
};

const auto mul = [] (unsigned lhs, unsigned rhs) {
    return unsigned(1ull * lhs * rhs % MOD);
};

unsigned qpow(unsigned a, unsigned n) {
    unsigned ans = 1;
    for (;n > 0;n >>= 1) {
        if (n & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, const vector<int>& nums) {
        unsigned buf[52];
        auto cur_cnt = buf;
        auto pre_cnt = buf + 26;
        fill_n(pre_cnt, 26, 0);
        for (char c : s)
            ++pre_cnt[c - 'a'];
        unsigned arr[52];
        arr[0] = s.size();
        vector<unsigned> pre, cur = {0};
        unsigned pre_d = arr[0];
        unsigned cnt = 1;
        for (unsigned i = 1;i < min(52, t + 1);++i) {
            // 差分优化 dp
            fill_n(cur_cnt, 26, 0);
            for (unsigned j = 0;j < 26;++j) {
                const unsigned l = (j + 1) % 26, r = l + nums[j];
                cur_cnt[l] = add(cur_cnt[l], pre_cnt[j]);
                if (r < 26)
                    cur_cnt[r] = sub(cur_cnt[r], pre_cnt[j]);
                else if (r > 26) {
                    cur_cnt[0] = add(cur_cnt[0], pre_cnt[j]);
                    cur_cnt[r - 26] = sub(cur_cnt[r - 26], pre_cnt[j]);
                }
            }
            for (unsigned j = 1;j < 26;++j)
                cur_cnt[j] = add(cur_cnt[j], cur_cnt[j - 1]);
            arr[i] = reduce(cur_cnt, cur_cnt + 26, 0ull) % MOD;
            swap(cur_cnt, pre_cnt);
            // Berlekamp–Massey 算法
            unsigned cur_d = arr[i];
            const unsigned l = cur.size();
            for (unsigned j = 0;j < l;++j)
                cur_d = sub(cur_d, mul(cur[j], arr[i - j - 1]));
            if (cur_d == 0) {
                ++cnt;
                continue;
            }
            const unsigned k = mul(cur_d, qpow(pre_d, MOD - 2));
            if (2 * l > i) {
                cur[cnt - 1] = add(cur[cnt - 1], k);
                for (unsigned j = 0;j < pre.size();++j)
                    cur[j + cnt] = sub(cur[j + cnt], mul(k, pre[j]));
                ++cnt;
            } else {
                auto tmp = cur;
                cur.resize(i + 1 - l, 0);
                cur[cnt - 1] = add(cur[cnt - 1], k);
                for (unsigned j = 0;j < pre.size();++j)
                    cur[j + cnt] = sub(cur[j + cnt], mul(k, pre[j]));
                pre = move(tmp);
                pre_d = cur_d;
                cnt = 1;
            }
        }
        const auto coff = cur.data();
        const unsigned l = cur.size();
        if (t < 52)
            return arr[t];
        else if (l == 0)
            return 0;
        else if (l == 1)
            return mul(arr[0], qpow(coff[0], t));
        else {
            // 常系数线性递推
            const auto polymul = [coff, l, &buf] (const unsigned* lhs, const unsigned* rhs, unsigned* ans) {
                fill_n(buf, 2 * l - 1, 0);
                for (unsigned i = 0;i < l;++i)
                    if (lhs[i] != 0)
                        for (unsigned j = 0;j < l;++j)
                            buf[i + j] = add(buf[i + j], mul(lhs[i], rhs[j]));
                for (unsigned i = 2 * l - 2;i >= l;--i)
                    if (buf[i] != 0)
                        for (unsigned j = 0;j < l;++j)
                            buf[i - j - 1] = add(buf[i - j - 1], mul(buf[i], coff[j]));
                copy_n(buf, l, ans);
            };
            unsigned base[26] = {};
            unsigned prod[26] = {};
            base[1] = prod[0] = 1;
            for (;t > 0;t >>= 1) {
                if (t & 1) polymul(base, prod, prod);
                polymul(base, base, base);
            }
            return inner_product(prod, prod + l, arr, 0ull, plus<uint64_t>{}, mul) % MOD;
        }
    }
};
