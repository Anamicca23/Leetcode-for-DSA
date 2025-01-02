class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;   
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size(),n = words.size();
        vector<int>res(q),csum(n);
        int sum=0;
        for(int i=0; i<n; i++){
            if(isvowel(words[i][0]) and isvowel(words[i].back()))sum++;
            csum[i]=sum;
        }
        for(int i=0; i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i]= csum[r]-((l>0)?csum[l-1]:0);
        }
        return res;
    }
};