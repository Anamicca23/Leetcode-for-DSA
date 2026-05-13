class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        int a,b,low,high,sum;
        for(int i = 0; i < n / 2; i++) {
            a = nums[i];
            b = nums[n - 1 - i];
            low = min(a, b) + 1;
            high = max(a, b) + limit;
            sum = a + b;
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            diff[low] -= 1;
            diff[high + 1] += 1;
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }
        int ans = INT_MAX;
        int moves = 0;
        for(int target = 2; target <= 2 * limit; target++) {
            moves += diff[target];
            ans = min(ans, moves);
        }
        return ans;
    }
};