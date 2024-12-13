class Solution {
public:
    #define P pair<int,int>
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n,false);
        priority_queue<P,vector<P>, greater<P>>minheap;
        for(int i =0; i<n; i++){
            minheap.push({nums[i],i});
        }
        long long score=0;
        while(!minheap.empty()){
            P temp = minheap.top();
            int element = temp.first;
            int idx = temp.second;
            minheap.pop();

            if(!visited[idx]){
                visited[idx]=true;
                score+=element;
                if(idx-1>=0 and !visited[idx-1])
                    visited[idx-1]=true;
                if(idx+1<n and !visited[idx+1])
                    visited[idx+1]=true;
            }
        }
        return score;
    }
};