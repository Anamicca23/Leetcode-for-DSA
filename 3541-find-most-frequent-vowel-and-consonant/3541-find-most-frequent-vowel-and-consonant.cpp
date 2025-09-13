class Solution {
public:
    int maxFreqSum(string s) {
        int count_v=0;
        int count_c=0;
        unordered_map<char,int>mp;
         for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                mp[s[i]]++;
                count_v=max(count_v,mp[s[i]]);
            }
            else{
            mp[s[i]]++;
                count_c=max(count_c,mp[s[i]]);
            }
        }
        return count_v+count_c;
    }
};