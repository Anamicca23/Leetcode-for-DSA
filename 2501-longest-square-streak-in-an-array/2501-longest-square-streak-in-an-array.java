import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int longestSquareStreak(int[] nums) {
        int mx = 0;
        int[] dp = new int[100001];
        
        for (int num : nums) {
            dp[num] = 1;
            mx = Math.max(mx, num);
        }

        int ans = -1;

        for (int i = 2; i <= mx; i++) {
            int root = (int) Math.sqrt(i);
            if (dp[i] > 0 && root * root == i) {
                dp[i] += dp[root];
                ans = Math.max(ans, dp[i]);
            }
        }

        return ans == 1 ? -1 : ans;
    }
}
