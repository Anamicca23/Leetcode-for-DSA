class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> vfreq;
        for(auto a : answers)
            vfreq[a + 1]++;

        int ans = 0;
        for(auto [f, n] : vfreq)
            ans += (n / f + (n % f != 0)) * (f);

        return ans;
    }
};