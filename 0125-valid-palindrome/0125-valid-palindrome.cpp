class Solution {
public:
    bool isPalindrome(string s) {
         int start=0, end=s.length()-1;
        while(start<end) {
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else {
                if (tolower(s[start++])!=tolower(s[end--])) return false;
            }
        }
        return true;    
    }

    bool isAlphaNumeric(char ch) {
        auto asciiCode = ch;
        if((asciiCode >= 'a' && asciiCode <= 'z') || (asciiCode >= '0' && asciiCode <= '9')) return true;
        return false;
    }
};