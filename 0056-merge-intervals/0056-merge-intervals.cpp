class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1; i<intervals.size();i++){
            if(ans[j][1]<intervals[i][0]){
                j++;ans.push_back(intervals[i]);
            }else{
                ans[j][1]= max(ans[j][1],intervals[i][1]);
            }
        }
        return ans;
    }
};