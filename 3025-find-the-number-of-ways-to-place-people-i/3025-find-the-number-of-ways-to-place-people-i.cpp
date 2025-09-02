class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        int res = 0, n = points.size();
        for (int i = 0; i < n; i++)
        {
            int b = points[i][1], last = -1;
            for (int j = i + 1; j < n; j++)
            {
                int a = points[j][1];
                if (a <= b && a > last)
                {
                    last = a;
                    ++res;
                }
            }
        }
        return res;
    }
};