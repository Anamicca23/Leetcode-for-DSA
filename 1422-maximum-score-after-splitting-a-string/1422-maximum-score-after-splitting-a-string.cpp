class Solution {
public:
    int maxScore(string s) {
        int ret = 0;   
        int n = s.size();
        vector <int> v(n);
        for(int i = 0; i < n; i++){
            if(i - 1 >= 0) v[i] += v[i - 1];
            v[i] += s[i] == '0';
        }
        int one = 0;
        for(int i = n - 1; i >= 1; i--){
            one += s[i] == '1';
            ret = max(ret, v[i - 1] + one);
        }
        return ret;
    }
};