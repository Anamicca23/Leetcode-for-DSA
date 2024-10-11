class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<int,vector<int>,greater<int>> chairs;

        targetFriend = times[targetFriend][0];
        sort(times.begin(),times.end());
        int start = 0,ans = 0;
        
        for(int i=0;;i++){
            int at = times[i][0], ct = times[i][1];
            while(!pq.empty() and pq.top().first<=at){
                chairs.push(pq.top().second);
                pq.pop();
            }

            if(!chairs.empty()){
                ans = chairs.top();
                chairs.pop();
            }
            else{
                ans = start;
                start++; 
            }
            pq.push({ct,ans});
            if(at==targetFriend){
                break;
            }
        }
        return ans;
    }
};