class Solution {
public:
    int findSmallestInteger(vector<int>& v, int val) {
        unordered_map<int, int> B;
        for (int x : v)
            B[((x % val) + val) % val]++;

        for (int i = 0; i <= v.size(); i++) {
            int rem = i % val;
            if (B.count(rem) && B[rem] > 0)
                B[rem] -= 1;
            else
                return i;
        }
        return 0;
    }
};