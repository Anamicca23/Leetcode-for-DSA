class Solution {
    private int find(int x, int[] parent) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    private boolean unionSets(int a, int b, int[] parent) {
        int ra = find(a, parent), rb = find(b, parent);
        if (ra == rb) 
            return true;
        parent[ra] = rb;
        return false;

    }

    public boolean containsCycle(char[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[] parent = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) 
            parent[i] = i;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j + 1 < cols && grid[i][j] == grid[i][j + 1]) {
                    if (unionSets(i * cols + j, i * cols + j + 1, parent)) 
                        return true;
                }
                if (i + 1 < rows && grid[i][j] == grid[i + 1][j]) {
                    if (unionSets(i * cols + j, (i + 1) * cols + j, parent)) 
                        return true;
                }
            }
        }
        return false;
    }
}