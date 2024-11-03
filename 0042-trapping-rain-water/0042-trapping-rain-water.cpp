class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ret = 0, maxVal = 0, idx = 0;
        for(int i = 0; i < n; i++) if(height[i] > maxVal) maxVal = height[i], idx = i;
        
        for(int i = 0, left = 0; i < idx; i++)
        left = max(left, height[i]), ret += left - height[i];
        for(int i = n - 1, right = 0; i > idx; i--) 
        right = max(right, height[i]), ret += right - height[i];
        
        return ret;
    }
};
