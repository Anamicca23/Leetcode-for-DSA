class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        rows = len(mat)
        cols = len(mat[0])
        
        k %= cols  
        
        if k == 0:
            return True  
        
        for i in range(rows):
            shifted_row = mat[i][k:] + mat[i][:k]
            
            if mat[i] != shifted_row:
                return False
        
        return True