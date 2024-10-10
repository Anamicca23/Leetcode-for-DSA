import java.util.Arrays;

class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int mwramp = 0;
        int[] rmax = new int[n];
        rmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = Math.max(rmax[i + 1], nums[i]);
        }

        int i = 0, j = 0;
        while (j < n) {
            while (i < j && nums[i] > rmax[j]) {
                i++;
            }
            mwramp = Math.max(mwramp, j - i);  
            j++;
        }
        return mwramp;
    }

}
