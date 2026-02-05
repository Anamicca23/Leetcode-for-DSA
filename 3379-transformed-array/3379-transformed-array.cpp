class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& A) {
        int n = A.size();
        int OFFSET = 1 << 7;
        int MASK = (1 << 8) - 1;

        for (int i = 0; i < n; i++)
            A[i] += OFFSET;

        for (int i = 0; i < n; i++) {
            int cur = A[i] - OFFSET;
            int idx = ((i + cur) % n + n) % n;
            int val = A[idx] & MASK;
            A[i] |= val << 8;
        }

        for (int i = 0; i < n; i++)
            A[i] = (A[i] >> 8) - OFFSET;

        return A;
    }
};