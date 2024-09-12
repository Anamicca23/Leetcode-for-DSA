class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bits=0;
        for(auto &c:allowed){
            bits |= ( 1 << (c-'a'));
        }
        int cnt=0;
        for(string &str:words){
            bool flag=true;
            for(char &ch:str){
                if(((bits >> (ch -'a')) & 1)==0){
                    flag=false;break;
                }
            }
            if(flag)cnt++;
        }
        return cnt;
    }
};