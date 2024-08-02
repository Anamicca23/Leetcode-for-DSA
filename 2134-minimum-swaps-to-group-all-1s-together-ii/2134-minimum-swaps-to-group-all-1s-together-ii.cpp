class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;

        // Calculate the total number of ones in the array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) total_ones++;
        }

        // Count ones in the initial window
        int current_ones = 0;
        for (int i = 0; i < total_ones; i++) {
            if (nums[i] == 1) current_ones++;
        }

        // Initialize variables for sliding window
        int i = 0, j = total_ones - 1, minSwaps = INT_MAX;

        // Slide the window over the circular array
        while (i < n) {
            // Update the minimum number of swaps needed
            minSwaps = min(minSwaps, total_ones - current_ones);

            // Slide the window to the right
            if (nums[i++] == 1) current_ones--;
            j++;

            // Handle wrap-around using modulo operation
            int index = j;
            if (j >= n) index = j - n;
            if (nums[index] == 1) current_ones++;
        }

        return minSwaps;
    }
};