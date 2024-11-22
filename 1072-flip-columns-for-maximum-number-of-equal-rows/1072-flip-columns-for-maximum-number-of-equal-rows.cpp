class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>freq;
        int n= matrix.size(),m = matrix[0].size();
        int maxlen =0;
        for(auto&curr:matrix){
            string chnge="";
            int firstch = curr[0];
            for(int i =0; i<m; i++)chnge+=(curr[i]==firstch?"A":"B");
            freq[chnge]++;
        }
        for(auto&it:freq)maxlen=max(maxlen,it.second);
        return maxlen;
    }
};