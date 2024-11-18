class Solution {
public:
    bool helper(int i, int n, vector<char>& chars) {
        if (i >= n / 2) return true;
        if (chars[i] != chars[n - i - 1]) return false;
        return helper(++i, n, chars);
    }

    bool isPalindrome(string s) {
        vector<char> chars;
        for (char c : s) {
            if (isalnum(c)) chars.push_back(tolower(c));
        }
        return helper(0, chars.size(), chars);
    }
};
