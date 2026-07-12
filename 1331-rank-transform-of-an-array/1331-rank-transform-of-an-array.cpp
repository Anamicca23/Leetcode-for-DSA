class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> rank;
        int currentRank = 1;

        for (int num : sorted) {
            if (!rank.count(num)) {
                rank[num] = currentRank++;
            }
        }
        for (int &num : arr) {
            num = rank[num];
        }
        return arr;
    }
};