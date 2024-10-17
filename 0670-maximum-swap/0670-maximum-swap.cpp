class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0, j = -1; i < s.size(); ++i)
            for (int d = 9; d > s[i] - '0'; --d)
                if ((j = s.find_last_of('0' + d)) > i) {
                    swap(s[i], s[j]);
                    return stoi(s);
                }
        return num;
    }
};
