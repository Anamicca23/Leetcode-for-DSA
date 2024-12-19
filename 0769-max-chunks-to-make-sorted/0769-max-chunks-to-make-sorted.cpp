class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0)return 0;
        int cnt=0,mx=0;
        for(int i=0;i<arr.size();i++){
            mx = max(arr[i],mx);
            if(mx==i)cnt++;
        }
        return cnt;
    }
};