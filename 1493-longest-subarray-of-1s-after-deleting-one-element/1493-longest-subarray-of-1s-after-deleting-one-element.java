class Solution {
    public int longestSubarray(int[] nums) {
        // Sliding window
        int n = nums.length;
        int i = 0, j = 0;
        int ans = 0, countzer = 0;
        
        while (j < n) {
            if (nums[j] == 0) {
                countzer++;
            }
            
            if (countzer > 1) {
                while (countzer > 1) {
                    if (nums[i] == 0) {
                        countzer--;
                    }
                    i++;
                }
            } else {
                ans = Math.max(ans, j - i);
            }
            
            j++;
        }
        
        return ans;
        // TC = O(n)
        // SC = O(1)
    }
}