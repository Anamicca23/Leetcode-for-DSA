class Solution {
    public int removeDuplicates(int[] nums) {
        int modIdx = 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[modIdx++] = nums[i + 1];
            }
        }
        return modIdx;
    }
}
