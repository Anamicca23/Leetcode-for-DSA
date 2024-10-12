class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
       priority_queue<int,vector<int>,greater<int>>pq;
       for(auto &val:intervals){
        int start = val[0];
        int end  = val[1];
        if(!pq.empty() and start>pq.top()){
            pq.pop();
        }
        pq.push(end);
       } 
       return pq.size();
    }
};