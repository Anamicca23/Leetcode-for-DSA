class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n;j++){
                if(grid[i][j]==1)cnt++;
            }
            if(cnt==n-1)return i;
        }
        return -1;
    }
};