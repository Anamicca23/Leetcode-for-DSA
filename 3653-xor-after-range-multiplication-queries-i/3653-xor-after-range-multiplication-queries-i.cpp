class Solution {
public:
    int xorAfterQueries(vector<int>& n, vector<vector<int>>& q) {
        int mod = 1e9 + 7;

        for (auto &a : q) {
            for (int i = a[0]; i <= a[1]; i += a[2]) {
                long long p = 1LL * n[i] * a[3];
                n[i] = (int)(p % mod);
            }
        }

        int s = 0;
        for (int x : n) s ^= x;

        return s;
    }
};