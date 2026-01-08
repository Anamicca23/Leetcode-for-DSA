class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>d(256,-1);
        int maxl=0, st=-1;
        for(int i=0; i<n;i++){
            if(d[s[i]]>st)
            st=d[s[i]];
            d[s[i]]=i;
            maxl=max(maxl,i-st);
        }
        return maxl;
        
    }
};