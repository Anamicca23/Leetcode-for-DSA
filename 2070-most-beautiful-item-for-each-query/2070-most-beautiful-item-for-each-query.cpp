class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& item, vector<int>& queries) {
        unordered_map<int,int> map;
        sort(item.begin(),item.end());
        int maxi = -1e9;
        for(auto&x:item) {
            maxi=max(maxi,x[1]);
            map[x[0]]=maxi;
        }
        vector<int> ans;
        for(auto&x:queries) {
            if(map.find(x)==map.end()) {
                int l = 0,r=item.size()-1,ansIdx=-1;
                while(l<=r){
                    int mid = (l+r)>>1;
                    if(item[mid][0] < x) {
                        ansIdx=mid;
                        l=mid+1;
                    } else {
                        r=mid-1;
                    }
                }
                ans.push_back(((ansIdx==-1)?0:map[item[ansIdx][0]]));
            } else {
              ans.push_back(map[x]);
            }
        }
        return ans;
    }
};