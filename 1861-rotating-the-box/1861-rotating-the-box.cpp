class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            int p = 0;
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '.') {
                    swap(grid[r][c], grid[r][p]);
                    p++;
                } else if (grid[r][c] == '*')
                    p = c + 1;
            }
        }
        
        vector<vector<char>> res(cols, vector<char>(rows));
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                res[c][rows - 1 - r] = grid[r][c];
                
        return res;
    }
};