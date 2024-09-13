class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>cxor(n,0);
        cxor[0]=arr[0];
        for(int i=1; i<n; i++)cxor[i]=cxor[i-1]^arr[i];
        vector<int>res;
        for(auto &q:queries){
            int l = q[0],r=q[1];
            int val = cxor[r]^(l==0?0:cxor[l-1]);
            res.push_back(val);
        }
        return res;
    }
};