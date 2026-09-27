class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()||s[i]!=')')
            {
                st.push(s[i]);
            }
          else if(s[i]==')')
            {
            queue<char>q;
                while(st.top() != '(')
                {
                 q.push(st.top());
                 st.pop();
                }
                st.pop();
                while(!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        s="";
        while(!st.empty())
                {
                  s=st.top()+s;
                    st.pop();
                }
                return s;
    }
};