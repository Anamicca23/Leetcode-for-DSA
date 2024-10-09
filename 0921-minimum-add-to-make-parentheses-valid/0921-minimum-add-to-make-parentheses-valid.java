class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0,openb=0;
        for(auto &c:s){
           (c == '(') ? size++ : (size > 0 ? size-- : openb++);
        }
        return openb+size;
    }
};