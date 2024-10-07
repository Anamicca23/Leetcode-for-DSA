class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && ((st.top() == 'A' && s[i] == 'B') ||
                (st.top() =='C' && s[i]=='D'))){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};