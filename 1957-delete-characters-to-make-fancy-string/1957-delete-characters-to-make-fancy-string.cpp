class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
         string res ="";
         int freq =1;
         res.push_back(s[0]);
         for(int i=1; i<n; i++){
            if(s[i]==res.back()){
                freq++;
                if(freq<3){
                    res.push_back(s[i]);
                }
            }else{
                res.push_back(s[i]);
                freq=1;
            }
         }
         return res;
    }
};