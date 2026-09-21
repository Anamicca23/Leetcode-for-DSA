class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] ans = new long[k];
        long[] dp = new long[k];

        for (int num : nums) {
            int x = num % k;
            long[] next = new long[k];
            next[x]++;

            for (int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                next[newR] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }
            dp = next;
        }
        return ans;
    }
}