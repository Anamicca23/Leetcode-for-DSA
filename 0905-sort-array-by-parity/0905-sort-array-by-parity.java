class Solution {
    public int[] sortArrayByParity(int[] nums) {
        // keep track of the next position to place an even number.
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            // it checks if the number is even by checking if nums[i] % 2 == 0.
            // If it is even, it means it should be placed at the next available position for even numbers.
            if (nums[i] % 2 == 0) {
                swap(nums, i, j++);
                // After swapping, it increments j to update the next available position for even numbers.
            }
        }
        return nums;
        // Finally, it returns the modified nums array as the sorted array by parity.
    }

    // Helper method to swap two elements in an array.
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
