class Solution {
    public int trap(int[] height) {
        int n = height.length, ret = 0, maxVal = 0, idx = 0;
        
        for (int i = 0; i < n; i++) 
            if (height[i] > maxVal) {
                maxVal = height[i];
                idx = i;
            }
        
        for (int i = 0, left = 0; i < idx; i++) {
            left = Math.max(left, height[i]);
            ret += left - height[i];
        }
        
        for (int i = n - 1, right = 0; i > idx; i--) {
            right = Math.max(right, height[i]);
            ret += right - height[i];
        }
        
        return ret;
    }
}
