class Solution {
    public int[] gcdValues(int[] A, long[] queries) {
        int max = Arrays.stream(A).max().getAsInt();

        int[] freq = new int[max + 1];
        long[] GCD = new long[max + 1];

        for (int a : A) freq[a]++;

        for (int i = max; i > 0; i--) {
            long sum = 0, extra = 0;
            for (int j = i; j <= max; j += i) {
                sum += freq[j];
                extra += GCD[j];
            }
            GCD[i] = sum * (sum - 1) / 2 - extra;
        }

        Arrays.parallelPrefix(GCD, Long::sum);
        int n = queries.length;

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            long q = queries[i];
            int l = 0, h = max + 1;
            while (l < h) {
                int m = (l + h) >>> 1;
                if (GCD[m] <= q) l = m + 1;
                else h = m;
            }
            res[i] = l;
        }

        return res;
    }
}