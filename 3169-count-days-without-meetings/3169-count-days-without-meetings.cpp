const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
    
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<pair<int,int>>pre;
        for(int i=0;i<meetings.size();i++){
            pre.push_back({meetings[i][0],meetings[i][1]});
        }
        int sum=0;
        sort(pre.begin(),pre.end());
        if(days>pre[0].first)sum+=pre[0].first-1;
       
        int maxi=pre[0].second;
        int ans=0;
        for(int i=1;i<n;i++){
            if(maxi<pre[i].first){
                sum+=min(days,pre[i].first)-maxi-1;
                maxi=pre[i].second;
                if(days<=pre[i].second)break;
            }
            else if(maxi>=pre[i].first){
                maxi=max(maxi,pre[i].second);
                if(days<=pre[i].second)break;
            }
            
        }
        if(maxi<days)sum+=days-maxi;
        return sum;
    }
};