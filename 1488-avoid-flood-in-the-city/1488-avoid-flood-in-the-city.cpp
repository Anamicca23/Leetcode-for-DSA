class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        vector<int> ans(n, 0);

        unordered_map<int,int> mp;

        

       set<int> index;
        
        for (int i = 0; i < n; i++) {

            if(rains[i]==0){
                index.insert(i);
                continue;
            }

            if (mp.find(rains[i]) != mp.end()) {
                if (index.size() == 0) {
                    return {};
                }

                else {
                   
                   auto it = index.lower_bound(mp[rains[i]]);

                   if(it==index.end()){
                    return {};
                   }

                   ans[*it]=rains[i];

                   index.erase(it);
                 

                   
                }
            }

            ans[i]=-1;
            mp[rains[i]]=i;
        }


        for(int i=0;i<n;i++){
            if(ans[i]==0){
                ans[i]=1;
            }
        }

        return ans;
    }
};