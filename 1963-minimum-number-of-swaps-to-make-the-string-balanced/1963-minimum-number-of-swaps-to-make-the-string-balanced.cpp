class Solution {
public:
    int minSwaps(string s) {
        int i = 0;
        int j = s.size() - 1;
        int cur = 0;
        int r = 0 ;
        while (i < j) {
            if (s[i] == '[') {
                ++cur;
            } else {
                --cur;
            }
            if (cur < 0) {
                while (s[j] != '[') {
                    --j;
                }
                swap(s[i], s[j]);
                ++r;
                cur = 1;
            }
            ++i;
        }
        return r;
    }
};