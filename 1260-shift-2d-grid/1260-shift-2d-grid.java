class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] changed = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = i * n + j;
                int newEle = (curr + k) % (m * n);
                int row = newEle / n;
                int col = newEle % n;
                changed[row][col] = grid[i][j];
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                temp.add(changed[i][j]);
            }
            result.add(temp);
        }
        return result;
    }
}