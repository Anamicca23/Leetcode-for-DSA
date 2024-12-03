class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        string res ="";
        for(int i=0,j=0;i<n;i++){
            if(j<m and i == spaces[j]){
                res+=" ",j++;
            }
            res+=s[i];
        }
        return res;
    }
};