class Solution {
public:
    int findKthNumber(long n, int k) {
        auto getGap = [&n](long a, long b) {
            long gap = 0;
            for (; a <= n; a *= 10, b *= 10)
                gap += min(n + 1, b) - a;
            return gap;
        };

        long cur = 1;
        for (int i = 1; i < k;) {
            long gap = getGap(cur, cur + 1);
            i + gap <= k ? (i += gap, ++cur) : (++i, cur *= 10);
        }
        return cur;
    }
};
