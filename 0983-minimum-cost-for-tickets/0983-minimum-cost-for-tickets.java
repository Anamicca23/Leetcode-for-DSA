import java.util.*;

class Solution {
    private int[] dp;
    
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        dp = new int[n];
        Arrays.fill(dp, -1);
        
        return calculateMinCost(0, days, costs, n);
    }
    
    private int calculateMinCost(int i, int[] days, int[] costs, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int ans = Integer.MAX_VALUE, j = i;
        for (int d : new int[] {1, 7, 30}) {
            while (j < n && days[j] < days[i] + d) j++;
            ans = Math.min(ans, calculateMinCost(j, days, costs, n) + 
                                costs[d == 1 ? 0 : d == 7 ? 1 : 2]);
        }
        return dp[i] = ans;
    }
}
