class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& d, vector<int>& walls) {
        int n = robots.size();
        vector<array<int,2>> x(n);
        for(int i=0; i<n; i++) x[i][0] = robots[i],x[i][1] = d[i];
        sort(walls.begin(),walls.end());
        sort(x.begin(),x.end());
        x.push_back({(int)1e9,0});

        // finds the no of walls in the range [l,r];
        auto query=[&](int l,int r){
            if(l>r) return 0;
            auto it1 = upper_bound(walls.begin(),walls.end(),r);
            auto it2 = lower_bound(walls.begin(),walls.end(),l);
            int res = it1-it2;
            return res;
        };
        
        vector<array<int,2>> dp(n);
        // base case
        dp[0][0] = query(x[0][0] - x[0][1],x[0][0]);
        if(n>1) dp[0][1] = query(x[0][0],min(x[1][0]-1, x[0][0]+x[0][1]));
        else dp[0][1] = query(x[0][0], x[0][0] + x[0][1]);

        //transition
        for(int i=1; i<n; i++){
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]) + query(x[i][0],min(x[i+1][0]-1,x[i][0]+x[i][1]));
            
            dp[i][0] = dp[i-1][0]+ query(max(x[i][0]-x[i][1],x[i-1][0]+1),x[i][0]);
            int res = dp[i-1][1] 
                        + query(max(x[i][0]-x[i][1],x[i-1][0]+1),x[i][0]) 
                        - query(max(x[i][0]-x[i][1],x[i-1][0]+1),min(x[i-1][0]+x[i-1][1],x[i][0]-1));
            dp[i][0] = max(res,dp[i][0]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};