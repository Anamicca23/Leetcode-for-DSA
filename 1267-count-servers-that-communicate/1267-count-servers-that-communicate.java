class Solution {
    public int countServers(int[][] grid) {
        //check for null input 
        if(grid == null || grid.length ==0)return 0;
        int rows = grid.length;
        int cols = grid[0].length;
        int[] rowCount = new int[rows];
        int[] colCount = new int[cols];
        int total = 0;
        //get the total number of servers on each row and col and in total
        for(int r=0; r< rows; r++) {
            for(int c=0; c< cols; c++) {
                if(grid[r][c] ==1){
                    total++;
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        for(int r=0; r< rows; r++){
            for(int c=0; c< cols; c++) {
                if(grid[r][c] ==1){//if there is a server
                    //if this is the only server on this row and this col(so it has no neighbor)
                    if(rowCount[r] ==1 && colCount[c] ==1) total--;
                }
            }
        }   
        return total;
    }
}
//Time complexity: O(r*c)
//space complexity: O(Max(r,c))