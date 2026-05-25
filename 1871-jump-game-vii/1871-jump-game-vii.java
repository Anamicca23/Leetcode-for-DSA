class Solution {
    public boolean canReach(String s, int minJ, int maxJ) {
        int n = s.length();

        if (s.charAt(n - 1) == '1')
            return false;

        int[] dp = new int[n];
        dp[0] = 1;
        int reach = 0, maxR = maxJ;

        for (int i = minJ; i < n; i++) {
            if (i > maxR) return false;

            reach += dp[i - minJ];
            if (i > maxJ) reach -= dp[i - maxJ - 1];

            if (reach > 0 && s.charAt(i) == '0') {
                dp[i] = 1;
                maxR = i + maxJ;
            }
        }

        return reach > 0;
    }
}