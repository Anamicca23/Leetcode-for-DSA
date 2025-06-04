class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if(numFriends == 1)return word;
        string res = "";
        for(int i =0; i<n; i++){
            res = max(res, word.substr(i,n-numFriends+1));
        }
        return res;
    }
};