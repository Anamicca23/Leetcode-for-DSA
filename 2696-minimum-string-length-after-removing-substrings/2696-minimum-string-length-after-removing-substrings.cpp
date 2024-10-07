class Solution {
public:
    int minLength(string s) {
        int i =0,j=1;
        while(j<s.length()){
            if(i<0){
                i++;
                s[i]=s[j];
            }else if((s[i]=='A' and s[j]=='B') ||(s[i]=='C' and s[j]=='D')){
                i--;
            }else {
                i++;
                s[i]=s[j];
            }
            j++;
        }
        return i+1;
    }
};