class Solution {
public:
    #define ll long long
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<ll> time(n, 0);
        for (auto &x: mana) {
            time[0] = time[0] + skill[0] * 1LL * x;
            for (int i = 1; i < n; i++) {
                time[i] = max(time[i], time[i - 1]) + skill[i] * 1LL * x;
            }
            for (int i = n - 2; i >= 0; i--) {
                time[i] = time[i + 1] - skill[i + 1] * 1LL * x;
            }
        }
        return time[n - 1];
    }
};