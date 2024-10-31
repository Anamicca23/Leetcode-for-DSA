import java.util.Arrays;
import java.util.List;

class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        int n = robot.size(), m = factory.length;
        int[] robotArray = robot.stream().mapToInt(Integer::intValue).toArray();
        
        long[] dp = new long[n + 1];
        Arrays.fill(dp, (long) 1e13);
        dp[0] = 0;
        Arrays.sort(robotArray);
        Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < m; i++) {
            int position = factory[i][0];
            int limit = factory[i][1];
            for (int l = 0; l < limit; l++) {
                for (int j = n - 1; j >= 0; j--) {
                    dp[j + 1] = Math.min(dp[j + 1], Math.abs(robotArray[j] - position) + dp[j]);
                }
            }
        }
        return dp[n];
    }
}
