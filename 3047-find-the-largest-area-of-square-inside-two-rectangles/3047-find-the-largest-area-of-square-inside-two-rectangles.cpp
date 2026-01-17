
class Solution {
public:
    long largestSquareArea(vector<std::vector<int>>& bottomLeft, vector<std::vector<int>>& topRight) {
        int ans = 0, n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            vector<int>& firstRectBL = bottomLeft[i];
            vector<int>& firstRectTR = topRight[i];
            for (int j = i + 1; j < n; j++) {
                vector<int>& secondRectBL = bottomLeft[j];
                vector<int>& secondRectTR = topRight[j];
                if (secondRectBL[0] >= firstRectTR[0] || secondRectTR[0] <= firstRectBL[0]) continue;
                if (secondRectTR[1] <= firstRectBL[1] || secondRectBL[1] >= firstRectTR[1]) continue;
                int pntAx = max(firstRectBL[0], secondRectBL[0]);
                int pntAy = max(firstRectBL[1], secondRectBL[1]);
                int pntBx = min(firstRectTR[0], secondRectTR[0]);
                int pntBy = min(firstRectTR[1], secondRectTR[1]);
                int sideA = pntBx - pntAx;
                int sideB = pntBy - pntAy;
                ans = max(ans, min(sideA, sideB));
            }
        }
        return static_cast<long>(ans) * ans;
    }
};