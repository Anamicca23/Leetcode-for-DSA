class Solution {
public:
    bool canDivide(vector<int>& nums, int maxBalls, int maxOperations) {
        int ops = 0;
        for (int n : nums) {
            ops += (n + maxBalls - 1) / maxBalls - 1;
            if (ops > maxOperations) return false;
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int res = right;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                right = mid;
                res = right;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};