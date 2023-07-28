class Solution {
    public void moveZeroes(int[] nums) {
        // Two Pointer Approach
        int i = 0, j = 0;
        // Move non-zero elements to the beginning of the array
        while (j < nums.length) {
            if (nums[j] == 0) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        // Fill the remaining positions with zeros
        while (i < nums.length) {
            nums[i++] = 0;
        }
    }
}
