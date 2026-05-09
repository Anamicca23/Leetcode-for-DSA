int layer[196]; 

class Solution {
public:
    static inline void inc(int& id, int p){ id=(id==p-1)?0:id+1; }
    static vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size(), L=min(r, c)/2;        
        for(int d=0; d<L; d++){
            const int si=d, sj=d, ei=r-d-1, ej=c-d-1;
            const int h=r-2*d, w=c-2*d; 
            const int p=(h+w-2)*2; 
            int id=0;
            for(int j=0; j<w-1; j++) 
                layer[id++]=grid[si][sj+j];
            for(int i=0; i<h-1; i++) 
                layer[id++]=grid[si+i][ej];
            for(int j=0; j<w-1; j++) 
                layer[id++]=grid[ei][ej-j];
            for(int i=0; i<h-1; i++) 
                layer[id++]=grid[ei-i][sj];
            id=k%p;

            for(int j=0; j<w-1; j++) 
                grid[si][sj+j]=layer[id], inc(id, p);
            for(int i=0; i<h-1; i++) 
                grid[si+i][ej]=layer[id], inc(id, p);
            for(int j=0; j<w-1; j++) 
                grid[ei][ej-j]=layer[id], inc(id, p);
            for(int i=0; i<h-1; i++) 
                grid[ei-i][sj]=layer[id], inc(id, p);
        }
        return grid;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();