class Solution {
public:
    typedef long long ll;
    bool solve(ll height,vector<int>&time,ll T){
        ll heightCanBeBreaken=0;
        for(auto ti:time){
           ll h=(-1+sqrt(1+(8*T)/ti))/2;
           heightCanBeBreaken+=h;
           if(heightCanBeBreaken>=height)return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low=0,high=1e18,ans=1e18;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(solve(1ll*mountainHeight,workerTimes,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};