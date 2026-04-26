class Solution {
public:
    int find(int x, vector<int>& parent) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool union_sets(int a, int b, vector<int>& parent) {
        int ra = find(a, parent), rb = find(b, parent);
        if (ra == rb) 
            return true;
        parent[ra] = rb;
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> parent(rows * cols);
        for (int i = 0; i < rows * cols; i++) 
            parent[i] = i;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j + 1 < cols && grid[i][j] == grid[i][j + 1]) {
                    if (union_sets(i * cols + j, i * cols + j + 1, parent)) 
                        return true;
                }
                if (i + 1 < rows && grid[i][j] == grid[i + 1][j]) {
                    if (union_sets(i * cols + j, (i + 1) * cols + j, parent)) 
                        return true;
                }
            }
        }
        return false;
    }
};