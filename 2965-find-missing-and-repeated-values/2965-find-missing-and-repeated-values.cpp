// x ^ 0 = x; x ^ x = 0; x ^ y = y ^ x;
// x ^ y = w; w ^ x = y; w ^ y = x;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> visited(n * n + 1, false);
        int repeatedValue = -1;
        // xor of all grid elements (b is missing, a will be canceled)
        int xorWithoutAB = 0; 
        // xor of (1..n^2)
        int xorOfAll = 0;
        // counter (1..n^2)
        int cnt = 1;

        for (auto& row : grid) {
            for (int element : row) {
                xorWithoutAB ^= element;
                xorOfAll ^= cnt;
                cnt += 1;
                if (repeatedValue == -1) {
                    if (visited[element]) {
                        repeatedValue = element;
                    } else {
                        visited[element] = true;
                    }
                }
            }
        }

        // a ^ b = xorWithoutAB ^ xorOfAll
        // b = a ^ b ^ repeatedValue
        int missingValue = xorWithoutAB ^ xorOfAll ^ repeatedValue;
        return {repeatedValue, missingValue};
    }
};