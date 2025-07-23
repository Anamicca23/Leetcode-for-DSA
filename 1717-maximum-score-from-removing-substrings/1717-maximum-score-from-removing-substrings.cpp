class Solution {
    int solve(string &s,string priority){
        int n=s.size();
        int count=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==priority[1] && st.top()==priority[0] ){
                st.pop();
                count++;

            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return count;
    }
public:
    int maximumGain(string s, int x, int y) {
        string l="";
        string h="";
        if(y>x){
            l="ab";
            h="ba";
            swap(x,y);
        }else{
            l="ba";
            h="ab";
        }
        int a=solve(s,h)*x; //high 15
        int b=solve(s,l)*y; //low
        return a+b;
    }
};