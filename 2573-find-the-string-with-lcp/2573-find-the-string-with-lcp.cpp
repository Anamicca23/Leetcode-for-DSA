class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size(), c = 0;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            if (A[i]) continue;
            if (++c > 26) return "";
            for (int j = i; j < n; ++j)
                if (lcp[i][j] > 0)
                    A[j] = c;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0;
                v = A[i] == A[j] ? v + 1 : 0;
                if (lcp[i][j] != v) return "";
            }
        }
        string res = "";
        for (int c : A)
            res += 'a' + c - 1;
        return res;
    }
};