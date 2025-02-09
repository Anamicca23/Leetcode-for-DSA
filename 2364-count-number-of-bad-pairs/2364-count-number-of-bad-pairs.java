import java.util.*;

class Solution {
    public long countBadPairs(int[] nums) {
        int b = nums.length;
        long g = 0;
        HashMap<Integer, Long> map = new HashMap<>();

        for (int i = 0; i < b; i++) {
            nums[i] = i - nums[i];
            map.put(nums[i], map.getOrDefault(nums[i], 0L) + 1);
        }

        for (long v : map.values()) {
            g += (v * (v - 1)) / 2;
        }

        return (long) b * (b - 1) / 2 - g;
    }
}
