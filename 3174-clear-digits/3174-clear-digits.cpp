class Solution {
public:
    string clearDigits(string s) {
        string res = ""; 
        for (char c : s) {
            if (isdigit(c)) {
                if (!res.empty()) {
                    res.pop_back(); 
                }
            } else {
                res.push_back(c); 
            }
        }
        return res;
    }
};