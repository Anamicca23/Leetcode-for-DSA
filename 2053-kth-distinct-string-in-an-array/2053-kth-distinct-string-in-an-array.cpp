class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
        for(auto str:arr){
            mpp[str]++;
        }

        int cnt=0;
        for(auto str:arr){
            if(mpp[str]==1){
                cnt++;
                if(cnt==k){
                    return str;
                }
            }
        }
        return "";
    }
};