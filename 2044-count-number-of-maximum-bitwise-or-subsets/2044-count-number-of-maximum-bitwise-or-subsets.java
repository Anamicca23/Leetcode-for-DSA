import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int subsetCount(int idx, int currOr, int[] nums, int maxOr, int[][] dp) {
        // Base case: if we've processed all elements
        if (idx == nums.length) {
            return currOr == maxOr ? 1 : 0;
        }
        // If the value is already computed, return it
        if (dp[idx][currOr] != -1) {
            return dp[idx][currOr];
        }
        
        // Including the current element in the subset
        int included = subsetCount(idx + 1, currOr | nums[idx], nums, maxOr, dp);
        
        // Not including the current element in the subset
        int notIncluded = subsetCount(idx + 1, currOr, nums, maxOr, dp);
        
        // Storing the result in dp array and returning the sum of both choices
        return dp[idx][currOr] = included + notIncluded;
    }

    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        // dp[idx][currOr]: count of subsets using first 'idx' elements with current OR 'currOr'
        int[][] dp = new int[nums.length][maxOr + 1];
        
        // Initialize dp array with -1 (uncomputed state)
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        
        // Start the recursive function
        return subsetCount(0, 0, nums, maxOr, dp);
    }
}