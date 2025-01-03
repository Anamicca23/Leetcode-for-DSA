import java.util.*;

public class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for (int num : nums) sum += num;

        long lsum = 0, rsum = 0;
        int splitCount = 0;

        for (int i = 0; i < n - 1; i++) {
            lsum += nums[i];
            rsum = sum - lsum;
            if (lsum >= rsum) splitCount++;
        }
        return splitCount;
    }
}
