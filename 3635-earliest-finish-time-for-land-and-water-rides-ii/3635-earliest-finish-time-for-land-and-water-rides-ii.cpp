class Solution {
public:

void getAns(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration ,int &ans)
{
        int minFinish = INT_MAX;
    
        for(int i = 0 ; i<landStartTime.size() ; i++)
            minFinish = min(minFinish , landStartTime[i] + landDuration[i]);

        for(int i = 0 ; i<waterStartTime.size() ; i++)
            ans = min(ans ,max( waterStartTime[i] , minFinish) + waterDuration[i]);
}

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        

        int ans = INT_MAX;

        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);

        swap(landStartTime,waterStartTime);
        swap(landDuration, waterDuration);

        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);

        return ans;
    }
};