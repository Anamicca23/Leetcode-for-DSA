class Solution {
public:
    int minimumPushes(string A) {
        auto q = A.size() >> 3, r = A.size() & 7;
        return ((q << 2) + r) * (q + 1);
    }
};