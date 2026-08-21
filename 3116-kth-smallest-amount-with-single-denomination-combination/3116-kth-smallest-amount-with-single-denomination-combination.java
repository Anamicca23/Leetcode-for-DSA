import java.util.Arrays;

class Solution {
    boolean check(long mid, int[] A, int n, int k) {
        long tot = 0;

        for (int i = 1; i <= n; i++) {
            int q = (1 << i) - 1;

            while (q < 1 << n) {
                long x = 1;

                for (int j = 0; j < n; j++)
                    if (((q >> j) & 1) != 0)
                        x = (x / gcd(x, A[j])) * A[j];

                tot += (mid / x) * (((i & 1) << 1) - 1);

                int c = q & -q;
                int r = q + c;
                q = (((r ^ q) >> 2) / c) | r;
            }
        }

        return tot >= k;
    }

    public long findKthSmallest(int[] coins, int k) {
        Arrays.sort(coins);

        int[] A = new int[coins.length];
        int n = 0;

        for (int c : coins) {
            boolean flag = true;

            for (int j = 0; j < n; j++)
                if (c % A[j] == 0) {
                    flag = false;
                    break;
                }

            if (flag)
                A[n++] = c;
        }

        long l = k;
        long r = (long) A[0] * k;

        while (l < r) {
            long mid = l + (r - l) / 2;

            if (check(mid, A, n, k))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}