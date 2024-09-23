class Solution {
    public int minExtraChar(String s, List<String> dictionary) {
        int n = s.length();
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (String word : dictionary) {
                int m = word.length();
                if (i >= m) {
                    boolean flag = true;
                    for (int j = i - m; j < i; ++j) {
                        if (s.charAt(j) != word.charAt(j - i + m)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        dp[i] = Math.min(dp[i], dp[i - m]);
                    }
                }
            }
        }
        return dp[n];
    }
}