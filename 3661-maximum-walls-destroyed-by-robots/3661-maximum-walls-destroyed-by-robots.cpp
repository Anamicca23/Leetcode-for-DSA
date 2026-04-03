#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // Pair robots with their distances and sort them by position
        vector<pair<int, int>> rd(n);
        for (int i = 0; i < n; ++i) {
            rd[i] = {robots[i], distance[i]};
        }
        sort(rd.begin(), rd.end());
        sort(walls.begin(), walls.end());

        // Filter out walls that are on the exact same position as a robot
        vector<int> w;
        int base_destroyed = 0;
        int i = 0, j = 0;
        
        while (i < walls.size() && j < n) {
            if (walls[i] < rd[j].first) {
                w.push_back(walls[i]);
                i++;
            } else if (walls[i] == rd[j].first) {
                base_destroyed++; // Guaranteed to be destroyed by this robot
                i++;
            } else {
                j++;
            }
        }
        while (i < walls.size()) {
            w.push_back(walls[i]);
            i++;
        }

        int idx = 0;
        int s = 0;
        
        // Process the first interval (-infinity to 1st Robot)
        while (idx < w.size() && w[idx] < rd[0].first) {
            idx++;
        }
        int e = idx;
        
        long long reach_L = (long long)rd[0].first - rd[0].second;
        // Count walls destroyed if the 1st robot shoots Left
        int dp0 = (w.begin() + e) - lower_bound(w.begin() + s, w.begin() + e, reach_L);
        int dp1 = 0;

        // Process strictly intermediate intervals between adjacent robots
        for (int k = 1; k < n; ++k) {
            s = idx;
            while (idx < w.size() && w[idx] < rd[k].first) {
                idx++;
            }
            e = idx;

            long long X = (long long)rd[k-1].first + rd[k-1].second; // Reach of Robot k-1 shooting Right
            long long Y = (long long)rd[k].first - rd[k].second;     // Reach of Robot k shooting Left

            // Walls covered by k-1 shooting Right
            int count_le_X = upper_bound(w.begin() + s, w.begin() + e, X) - (w.begin() + s);
            // Walls covered by k shooting Left
            int count_ge_Y = (w.begin() + e) - lower_bound(w.begin() + s, w.begin() + e, Y);
            
            // Walls covered if BOTH k-1 shoots Right AND k shoots Left
            int count_union = 0;
            if (X >= Y) {
                count_union = e - s; // Full overlap, all walls in this sub-interval are hit
            } else {
                count_union = count_le_X + count_ge_Y;
            }

            // Update DP transitions
            int next_dp0 = max(dp0 + count_ge_Y, dp1 + count_union);
            int next_dp1 = max(dp0 + 0, dp1 + count_le_X);
            
            dp0 = next_dp0;
            dp1 = next_dp1;
        }

        // Process the final interval (last Robot to +infinity)
        s = idx;
        e = w.size();
        long long X_last = (long long)rd[n-1].first + rd[n-1].second;
        int count_last = upper_bound(w.begin() + s, w.begin() + e, X_last) - (w.begin() + s);

        int ans = max(dp0, dp1 + count_last);

        return ans + base_destroyed;
    }
};