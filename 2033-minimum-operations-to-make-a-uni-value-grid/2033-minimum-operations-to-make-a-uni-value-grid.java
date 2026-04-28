class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length, n = grid[0].length;
        int[] nums = new int[m * n];
        int index = 0;
        for (int[] row : grid) {
            for (int k : row) {
                nums[index++] = k;
            }
        }
        Arrays.sort(nums);
        int target = nums[nums.length / 2];
        int totalOperations = 0;
        for (int k : nums) {
            int temp = Math.abs(k - target);
            if (temp % x != 0) return -1;
            totalOperations += temp / x;
        }
        return totalOperations;
    }
}