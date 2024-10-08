class Solution {
public:
    int minSwaps(string s) {
        int sz = 0;
        for(auto &it: s){
           (it == '[') ? sz++ : (sz > 0 ? sz-- : sz);
        }
        return (sz+1)/2;
    }
};