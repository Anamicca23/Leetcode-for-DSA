class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                newStr += tolower(c);
            }
        }
        
        string reversed = newStr;
        reverse(reversed.begin(), reversed.end());
        
        return newStr == reversed;
    }
};