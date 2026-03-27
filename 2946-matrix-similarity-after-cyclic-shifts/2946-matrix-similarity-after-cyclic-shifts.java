class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int rows = mat.length;
        int cols = mat[0].length;
        
        k %= cols;
        
        if (k == 0) {
            return true;  
        }
        
        for (int i = 0; i < rows; i++) {
            int[] shifted_row = new int[cols];
            for (int j = 0; j < cols; j++) {
                shifted_row[j] = mat[i][(j + k) % cols];
            }
            
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] != shifted_row[j]) {
                    return false; 
                }
            }
        }
        
        return true;
    }
}