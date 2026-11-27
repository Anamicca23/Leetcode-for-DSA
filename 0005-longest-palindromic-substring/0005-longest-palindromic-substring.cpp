class Solution {
public:
    string getUpdatedString(string& s) {
        int n = s.size();
        string updatedString = "#";
        for (int i = 0; i < n; i++) {
            updatedString += s[i];
            updatedString += "#";
        }
        return updatedString;
    }
    
    string longestPalindrome(string s) {
        s = getUpdatedString(s);
        int n = s.size();
        vector<int> palindromeLength(n, 0);
        int right = 0, centre = 0;
        
        for (int i = 0; i < n; i++) {
            int mirror = 2 * centre - i;
            if (i < right) {
                palindromeLength[i] = min(right - i, palindromeLength[mirror]);
            }
            
            int left = i - (1 + palindromeLength[i]);
            int nextRight = i + (1 + palindromeLength[i]);
            while (left >= 0 && nextRight < n && s[left] == s[nextRight]) {
                palindromeLength[i]++;
                left--;
                nextRight++;
            }
            
            if (i + palindromeLength[i] > right) {
                centre = i;
                right = i + palindromeLength[i];
            }
        }
        
        int maxLen = 0, centreIdx = 0;
        for (int i = 0; i < n; i++) {
            if (palindromeLength[i] > maxLen) {
                maxLen = palindromeLength[i];
                centreIdx = i;
            }
        }
        
        string result = "";
        for (int i = centreIdx - maxLen; i <= centreIdx + maxLen; i++) {
            if (s[i] != '#') {
                result += s[i];
            }
        }
        return result;
    }
};
