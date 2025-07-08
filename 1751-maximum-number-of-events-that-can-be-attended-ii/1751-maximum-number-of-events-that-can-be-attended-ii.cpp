class Solution {
public:
vector<vector<int>>dp;

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        int n = events.size();
        dp.resize( n, vector<int>( k + 1, -1));
        return solve(events , 0 , k , 0);
    }
    int solve(vector<vector<int>>& events,int i, int k,int end){
        if(i==events.size()) return 0;

        if( k==0 ) return 0;

        if( events[i][0] <= end ) return solve( events, i + 1 , k , end );

        if( dp[i][k] != -1) return dp[i][k];

        int choices= max ( events[i][2] + solve(events, i + 1, k - 1 , events[i][1] ),  solve(events , i + 1 , k , end ) );
        return dp[i][k] = choices;
    }
};