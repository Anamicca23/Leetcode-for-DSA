class Solution {
public:
    long long dp[100][100][100];
    long long f(int i, int j, int k, vector<int>& robot, vector<vector<int>>& factory)
    {
        if (i<0) return 0;
        if (j<0) return 1LL<<40;
        if (dp[i][j][k]!=-1) return dp[i][j][k];
        int xR=robot[i], xF=factory[j][0];
        long long otherFactory=f(i, j-1, 0, robot, factory);
        long long factoryJ=(k<factory[j][1])?abs(xR-xF)+f(i-1, j, k+1, robot, factory):1LL<<40;
        return dp[i][j][k]=min(otherFactory,  factoryJ);

    }
    void print(auto& c){
        for(int x:c) cout<<x<<", ";
        cout<<endl;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n=robot.size(), m=factory.size();
        memset(dp, -1, sizeof(dp));
        return f(n-1, m-1, 0, robot, factory);
    }
};
