class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;
        int[] zeros = new int[n];
        if (Arrays.equals(nums, zeros)) {
            return 0;
        }
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x != 0 ? n : n - 1;
    }
}