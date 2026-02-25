class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), 
        [](unsigned x, unsigned y){
            return popcount(x)==popcount(y)?x<y
            : popcount(x)<popcount(y);
        });
        return arr;
    }
};