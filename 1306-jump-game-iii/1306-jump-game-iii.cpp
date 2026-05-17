class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        if (cur < 0 || cur >= size(A) || A[cur] < 0)
            return false;
        A[cur] *= -1;
        return !A[cur] || canReach(A, cur + A[cur]) ||
               canReach(A, cur - A[cur]);
    }
};