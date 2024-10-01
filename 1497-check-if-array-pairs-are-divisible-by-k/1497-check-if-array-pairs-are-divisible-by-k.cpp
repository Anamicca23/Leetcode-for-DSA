class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>hs(k,0);
        for(int &it:arr){
            int rem=(it%k+k)%k;
            hs[rem]++;
        }
        if(hs[0]%2)return false;
        for(int i=1;i<=k/2;i++){
            if(hs[k-i]!=hs[i])return false;
        }
        return true;
    }
};