class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int trail = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
                trail++;
            grid[i][0] = trail;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int j, req = n - 1 - i;
            for (j = 0; j < grid.size(); j++)
                if (grid[j][0] >= req) break;
            if (j == grid.size()) return -1;
            swaps += j;
            grid.erase(grid.begin() + j);
        }

        return swaps;
    }
};