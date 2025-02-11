class Solution {
public:
    bool check(stack<char>& st, string& part, int m) {
        stack<char> tempst = st;
        for (int idx = m - 1; idx >= 0; idx--) {
            if (tempst.empty() || tempst.top() != part[idx]) return false;
            tempst.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length(), m = part.length();

        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            if ((int)st.size() >= m && check(st, part, m)) {
                for (int j = 0; j < m; j++) st.pop();
            }
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
