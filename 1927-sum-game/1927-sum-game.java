class Solution {
    public boolean sumGame(String A) {
        int[] sum = {0, 0}, q = {0, 0};
        int n = A.length();
        for (int i = 0; i < n; i++) {
            int j = i / (n >> 1);
            if (A.charAt(i) == '?')
                q[j]++;
            else
                sum[j] += A.charAt(i) - '0';
        }
        return ((q[0] + q[1]) % 2 == 1) ||
               ((sum[0] - sum[1]) << 1) != (q[1] - q[0]) * 9;
    }
}