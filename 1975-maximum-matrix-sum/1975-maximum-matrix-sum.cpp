class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum =0; int ncnt=0,absmin =INT_MAX;
        for(auto &r:matrix){
            for(int x:r){
                sum+=abs(x);
                if(x<0)ncnt++;
                absmin= min(absmin,abs(x));
            }
        }
        return (ncnt&1?sum-2*absmin:sum);
    }
};