class Solution {
    public int findChampion(int[][] grid) {
        int candidate = 0;
        for(int i = 0; i < grid.length; i++){
            if(grid[i][candidate] == 1) candidate = i;
        }
        return candidate;
    }
}