class Solution {
    static final int MOD = 1000000007;
    long modpow(long a, long e) {
        long r = 1;
        a %= MOD;
        while (e > 0) {
            if ((e & 1) == 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int B = (int)Math.sqrt(n) + 1;
        List<List<List<long[]>>> events = new ArrayList<>();
        for (int i = 0; i <= B; i++) {
            events.add(new ArrayList<>());
        }
        for (int k = 1; k <= B; k++) {
            List<List<long[]>> temp = new ArrayList<>();
            for (int rem = 0; rem < k; rem++) {
                temp.add(new ArrayList<>());
            }
            events.set(k, temp);
        }
        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)((long)nums[i] * v % MOD);
                }
            } else {
                int rem = l % k;
                int start = (l - rem) / k;
                int end = (r - rem) / k;

                events.get(k).get(rem).add(new long[]{start, v});

                int maxT = (n - 1 - rem) / k;
                if (end + 1 <= maxT) {
                    long inv = modpow(v, MOD - 2);
                    events.get(k).get(rem).add(new long[]{end + 1, inv});
                }
            }
        }
        for (int k = 1; k <= B; k++) {
            for (int rem = 0; rem < k; rem++) {
                List<long[]> ev = events.get(k).get(rem);
                if (ev.isEmpty()) continue;
                ev.sort(Comparator.comparingLong(a -> a[0]));
                List<long[]> comp = new ArrayList<>();
                for (long[] p : ev) {
                    if (!comp.isEmpty() && comp.get(comp.size() - 1)[0] == p[0]) {
                        long[] last = comp.get(comp.size() - 1);
                        last[1] = (last[1] * p[1]) % MOD;
                    } else {
                        comp.add(new long[]{p[0], p[1]});
                    }
                }
                long cur = 1;
                int ptr = 0;

                for (int t = 0, idx = rem; idx < n; t++, idx += k) {
                    while (ptr < comp.size() && comp.get(ptr)[0] == t) {
                        cur = (cur * comp.get(ptr)[1]) % MOD;
                        ptr++;
                    }
                    nums[idx] = (int)((long)nums[idx] * cur % MOD);
                }
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
}