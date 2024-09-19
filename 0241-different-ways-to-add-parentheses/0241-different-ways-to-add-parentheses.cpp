class Solution {
public:
    vector<int>solve(string s){
        vector<int>res;
        for(int i=0; i<s.length();i++){
           char c=s[i];
           if(c=='+' || c=='-' || c=='*'){
              vector<int>left = solve(s.substr(0,i));
              vector<int>right= solve(s.substr(i+1));
              for(auto &l:left){
                for(auto &r:right){
                    (c=='+')?res.push_back(l+r):((c=='-')?res.push_back(l-r):res.push_back(l*r));
                    }
                  }
                }
            }
        if(res.empty())res.push_back(stoi(s));
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};