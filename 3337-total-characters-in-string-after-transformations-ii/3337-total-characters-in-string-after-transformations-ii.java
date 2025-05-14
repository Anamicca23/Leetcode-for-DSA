public class Solution {
    public static final int MOD = 1000000007;
    public static final long M2 = (long) MOD * MOD;
    public static final long BIG = 8L * M2;

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int[][] m = new int[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums.get(i); j++) {
                m[(i + j) % 26][i]++;
            }
        }
        int[] v = new int[26];
        for (char c : s.toCharArray()) {
            v[c - 'a']++;
        }
        v = pow(m, v, t);
        long ans = 0;
        for (int x : v) {
            ans += x;
        }
        return (int) (ans % MOD);
    }

    private int[] pow(int[][] a, int[] v, long e) {
        for (int i = 0; i < v.length; i++) {
            if (v[i] >= MOD) {
                v[i] %= MOD;
            }
        }
        int[][] mul = a;
        for (; e > 0; e >>>= 1) {
            if ((e & 1) == 1) {
                v = mul(mul, v);
            }
            mul = p2(mul);
        }
        return v;
    }

    private int[] mul(int[][] a, int[] v) {
        int m = a.length;
        int n = v.length;
        int[] w = new int[m];
        for (int i = 0; i < m; i++) {
            long sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (long) a[i][k] * v[k];
                if (sum >= BIG) {
                    sum -= BIG;
                }
            }
            w[i] = (int) (sum % MOD);
        }
        return w;
    }

    private int[][] p2(int[][] a) {
        int n = a.length;
        int[][] c = new int[n][n];
        for (int i = 0; i < n; i++) {
            long[] sum = new long[n];
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    sum[j] += (long) a[i][k] * a[k][j];
                    if (sum[j] >= BIG) {
                        sum[j] -= BIG;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                c[i][j] = (int) (sum[j] % MOD);
            }
        }
        return c;
    }
}