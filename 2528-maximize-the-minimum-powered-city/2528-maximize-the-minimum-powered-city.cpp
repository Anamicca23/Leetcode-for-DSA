class Solution {
public:
    #define ll long long
    bool canAchieve(vector<int>& stations, int r, ll k, ll target) {
        int n = stations.size();
        vector<ll> add(n, 0);
        ll used = 0, windowSum = 0;

        for (int i = 0; i <= r && i < n; i++) windowSum += stations[i];

        for (int i = 0; i < n; i++) {
            if (i - r - 1 >= 0) windowSum -= stations[i - r - 1] + add[i - r - 1];
            if (i + r < n && i != 0) windowSum += stations[i + r] + add[i + r];

            if (windowSum < target) {
                ll need = target - windowSum;
                if (used + need > k) return false;
                used += need;
                add[min(n - 1, i + r)] += need;
                windowSum += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        ll low = 0, high = 0;
        for (int s : stations) high += s;
        high += k;

        ll ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (canAchieve(stations, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};