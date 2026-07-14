class Solution {
    private static final int MOD = 1_000_000_007;
    private int n;
    private int[][][] dp;

    private int solve(int idx, int g1, int g2, int[] nums) {
        if (idx == n) {
            return (g1 != 0 && g1 == g2) ? 1 : 0;
        }
        if (dp[idx][g1][g2] != -1)
            return dp[idx][g1][g2];
        long ans = 0;
        ans = solve(idx + 1, g1, g2, nums);
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, ng1, g2, nums)) % MOD;
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, ng2, nums)) % MOD;
        return dp[idx][g1][g2] = (int) ans;
    }

    public int subsequencePairCount(int[] nums) {
        n = nums.length;
        dp = new int[n + 1][201][201];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 200; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(0, 0, 0, nums);
    }
    private int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}