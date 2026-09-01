class Solution {
    int dir[5] = {-1,0,1,0,-1};
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();  // 1-20
        int n = classroom[0].size();  // 1-20
        int stx, sty;      
        int trash = 0; // pos -> index
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(classroom[i][j] == 'S'){
                    stx = i; sty = j;
                } else if(classroom[i][j] == 'L'){
                    classroom[i][j] = '0' + trash;
                    ++trash;
                }
            }
        }
        if(trash == 0)
            return 0;
        int bitMax = (1 << trash) - 1; // reach it and return
        // from hint, same status if already run bigger energy, smaller one can skip
        int maxEng[20][20][1024];    
        memset(maxEng, -1, sizeof(maxEng));

        // run BFS
        queue<tuple<int, int, int, int>> q;
        q.push({stx, sty, energy, 0});
        maxEng[stx][sty][0] = energy; // from hint
        int step = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int run=0; run < sz; ++run){
                auto [x, y, en, mask] = q.front(); 
                q.pop();
                if(mask == bitMax) return step;
                if(en == 0) continue;
                for(int i=0; i<4; ++i){
                    int nextX = x + dir[i];
                    int nextY = y + dir[i+1];
                    if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || classroom[nextX][nextY] == 'X') continue;
                    int nextEn = en - 1;
                    int nextMask = mask;
                    if(classroom[nextX][nextY] == 'R')
                        nextEn = energy;
                    else if(classroom[nextX][nextY] <= '9' && classroom[nextX][nextY] >= '0'){
                        nextMask |= 1 << (classroom[nextX][nextY] - '0');
                    }
                    if(maxEng[nextX][nextY][nextMask] < nextEn){
                        maxEng[nextX][nextY][nextMask] = nextEn;
                        q.push({nextX, nextY, nextEn, nextMask});    
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};