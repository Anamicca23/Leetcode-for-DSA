class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inte) {
        sort(inte.begin(), inte.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });

        int n = inte.size();
        int ans = n;

        int low = inte[0][0];
        int high = inte[0][1];

        for (int i = 1; i < n; i++) {
            if (inte[i][0] == low || inte[i][1] <= high) {
                ans--;
            } else {
                low = inte[i][0];
                high = inte[i][1];
            }
        }

        return ans;
    }
};