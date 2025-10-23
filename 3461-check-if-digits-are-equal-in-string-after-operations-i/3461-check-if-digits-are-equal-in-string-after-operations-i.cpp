class Solution {
public:
    bool hasSameDigits(string s) {
        int iteration = 0; 
        while (s.size() - iteration != 2) {
            for (int i = 0; i < s.size() - 1 - iteration; i++) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            iteration++;
        }
        return s[0] == s[1];
    }
};