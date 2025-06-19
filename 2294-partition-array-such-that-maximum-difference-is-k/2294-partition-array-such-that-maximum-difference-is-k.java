import java.util.Arrays;

class Solution {
  public int partitionArray(int[] nums, int k) {
    Arrays.sort(nums);
    int ans = 1, l = 0;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] - nums[l] > k) {
        ans++;
        l = i;
      }
    }
    return ans;
  }
}