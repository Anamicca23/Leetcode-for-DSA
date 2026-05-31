unsigned freq[100001] = {0};
class Solution {
public:
    static bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned xmax = 0, xmin = 1e5;
        for (unsigned x : asteroids) {
            freq[x]++;
            xmin = min(xmin, x);
            xmax = max(xmax, x);
        }
        long long planet = mass;
        for (int x = xmin; x <= xmax; x++) {
            if (freq[x] == 0)
                continue;
            if (x > planet) {
                memset(freq + x, 0, (xmax - x + 1) * sizeof(unsigned));
                return 0;
            }
            planet += (long long)x * freq[x];
            freq[x] = 0;
        }
        return 1;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();