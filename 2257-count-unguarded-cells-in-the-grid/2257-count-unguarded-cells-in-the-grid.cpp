class Solution {
public:
    void markedguarded(int row, int col, vector<vector<int>>&grid){
        for(int i= row-1;i>=0;i--){
            if(grid[i][col]==2 || grid[i][col]==3)break;
            grid[i][col]=1;
        }

        for(int i= row+1;i<grid.size();i++){
            if(grid[i][col]==2 || grid[i][col]==3)break;
            grid[i][col]=1;
        }

        for(int j= col-1;j>=0;j--){
            if(grid[row][j]==2 || grid[row][j]==3)break;
            grid[row][j]=1;
        }

        for(int j= col+1;j<grid[0].size();j++){
            if(grid[row][j]==2 || grid[row][j]==3)break;
            grid[row][j]=1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto &vec:guards){
            int i=vec[0],j=vec[1];
            grid[i][j]=2;
        }
        for(auto&vec:walls){
            int i=vec[0],j=vec[1];
            grid[i][j]=3;
        }
        for(auto & guard:guards){
            int i=guard[0],j=guard[1];
            markedguarded(i,j,grid);
        }
        int cnt=0;
        for(int i=0;i<m;i++)
           for(int j=0; j<n;j++)
                if(grid[i][j]==0)cnt++;

        return cnt;        
    }
};