class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = nums[0];
        for (int i = 1; i < n; i++) {
            res[i] = Math.max(res[i - 1], nums[i]);
        }

        int min_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (res[i] > nums[min_idx]) {
                res[i] = res[min_idx];
            }

            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
        }
        return res;
    }
}