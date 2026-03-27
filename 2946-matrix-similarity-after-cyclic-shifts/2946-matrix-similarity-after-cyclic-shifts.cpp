class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        k %= cols;
        if (k == 0) {
            return true;
        }
        
        for (int i = 0; i < rows; i++) {
            vector<int> shifted(mat[i].begin() + k, mat[i].end());
            shifted.insert(shifted.end(), mat[i].begin(), mat[i].begin() + k); 
            if (mat[i] != shifted) {
                return false;
            }
        }
        return true;
    }
};