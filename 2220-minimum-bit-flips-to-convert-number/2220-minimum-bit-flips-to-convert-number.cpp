class Solution {
public:
    int minBitFlips(int start, int goal) {
        int getres = start^goal;
        return __builtin_popcount(getres);
    }
};