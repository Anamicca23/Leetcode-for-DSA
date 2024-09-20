class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string ss = s + '#' + string(s.rbegin(),s.rend());
        vector<int> lps(ss.size());

        for(int i=1; i<ss.size(); i++){
            int j = lps[i-1];

            while(j>0 && ss[i] != ss[j]){
                j = lps[j-1];
            }

            if(ss[i] == ss[j]){
                j++;
            }

            lps[i] = j;
        }

        return string(s.rbegin(),s.rend()).substr(0,n-lps.back()) + s;
    }
};