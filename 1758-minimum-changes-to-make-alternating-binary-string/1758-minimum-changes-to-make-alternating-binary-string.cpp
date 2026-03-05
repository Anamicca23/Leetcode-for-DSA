class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;

        for(int i=0; i<s.size(); ++i) {
            char expected1 = (i % 2) == 0 ? '0' : '1';
            char expected2 = (i % 2) == 0 ? '1' : '0';

            if(s[i] != expected1) count1++;
            if(s[i] != expected2) count2++;
        }
        return min(count1, count2);
    }
};