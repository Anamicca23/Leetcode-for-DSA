import java.util.*;

class Solution {
    public int findMaxK(int[] nums) {
        boolean[] exist = new boolean[2001];
        int ans = -1;
        for (int num : nums) {
            if (exist[-num + 1000]) {
                ans = Math.max(ans, Math.abs(num));
            }
            exist[num + 1000] = true;
        }
        return ans;
    }
}
