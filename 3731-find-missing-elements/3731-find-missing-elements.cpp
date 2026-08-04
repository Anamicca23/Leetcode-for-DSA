class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        __uint128_t hasX=0;
        int xMin=101, xMax=0;
        for(int x: nums){
            hasX|=((__uint128_t)1<<x);
            xMin=min(x, xMin);
            xMax=max(x, xMax);
        }
        vector<int> ans;
        for(int x=xMin+1; x<xMax; x++)
            if (((hasX>>x)&1)==0) ans.push_back(x);
        return ans;
    }
};