class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int ret = 0;
        int maxVal = height[0];
        int idx = 0;
        
        for(int i = 0; i < n; i++){
            if(height[i] > maxVal){
                maxVal = height[i];
                idx = i;
            }
        }
        int left = 0;
        int right = 0;
        for(int i = 0; i < idx; i++){
            left = max(left, height[i]);
            ret += left - height[i];
        }
        for(int i = n - 1; i > idx; i--){
            right = max(right, height[i]);
            ret += right - height[i];
        }
        return ret;
    }
};