class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            top += grid[0][i];
        }

        long long bottom = 0, res = LLONG_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            top -= grid[0][i]; // First robot picks from the top row 
            res = min(res, max(top, bottom)); // Minimize the maximum score for the second robot
            bottom += grid[1][i]; // Second robot picks from the bottom row \U0001f916
        }
        return res; 
    }
};