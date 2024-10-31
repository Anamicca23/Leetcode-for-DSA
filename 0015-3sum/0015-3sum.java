import java.util.*;

class Solution {
    private List<List<Integer>> res = new ArrayList<>();

    private void twosum(int[] nums, int targ, int i, int j) {
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < targ) {
                i++;
            } else if (sum > targ) {
                j--;
            } else {
                res.add(Arrays.asList(-targ, nums[i], nums[j]));
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                i++;
                j--;
            }
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        if (n < 3) return res;

        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates
            int targ = -nums[i];
            twosum(nums, targ, i + 1, n - 1);
        }
        return res;
    }
}
