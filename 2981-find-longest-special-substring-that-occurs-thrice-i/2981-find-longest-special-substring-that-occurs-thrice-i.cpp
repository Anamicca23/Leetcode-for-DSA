class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<char,int>,int>mapie;
        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == s[i]) {
                    l++;
                    mapie[{s[i], l}]++;
                } else {
                    break;
                }
            }
        }
        int res =0;
        for(auto &it:mapie){
            int len= it.first.second;
            int freq = it.second;
            if(freq>=3 and len >res){
                res = len;
            }
        }
        return (res==0?-1:res);
    }
};