class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
    int n = s.length();
    int pos = -1e9;
    vector<int> ans(n, n);

   for (int i = 0; i >= 0; ans[n-1] == n ? ++i : --i) {
        int index = i % n;
        if (s[index] == c) {
            pos = index;
        }
        ans[index] = min(ans[index], abs(index - pos));
    }
    return ans;
    }
};