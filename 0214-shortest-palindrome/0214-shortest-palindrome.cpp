class Solution {
public:
    vector<int>z_function(string s){
        int n=s.length();
        vector<int>z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(r>i){
                z[i]=min(z[i-l],r-i);
            }
            while(i+z[i]<n && s[i+z[i]]==s[z[i]])z[i]++;
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }
    string shortestPalindrome(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        t=s+"#"+t;
        vector<int>z=z_function(t);
        int mxpal=0;
        for(int i=0;i<n;i++){
            if(z[2*n-i]==i+1){
                mxpal=i+1;
            }
        }
        string ans=s.substr(mxpal,n-mxpal);
        reverse(ans.begin(),ans.end());
        return ans+s;
    }
};