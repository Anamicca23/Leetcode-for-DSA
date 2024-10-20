class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c: expression) {
            if (c == ')') {
                vector<bool> exp;
                while (stk.top() != '(') exp.push_back(stk.top() == 't'), stk.pop();
                stk.pop();
                char op = stk.top(); stk.pop();
                bool res = exp[0];
                if (op == '&') for (bool e : exp) res &= e;
                else if (op == '|') for (bool e : exp) res |= e;
                else res = !res;
                stk.push(res ? 't' : 'f');
            } else if (c != ',') stk.push(c);
        }
        return stk.top() == 't';
    }
};
