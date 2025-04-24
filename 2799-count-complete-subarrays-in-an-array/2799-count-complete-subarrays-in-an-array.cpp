class Solution {
public:
    int countCompleteSubarrays(vector<int>& A) {
        vector<int> C(2050, 0);
        int n = A.size();
        for(auto c : A) C[c] = 1;
        int dis = 0;
        for(auto c : C) dis += c;
        for(auto c : A) C[c] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = i; j < n; j++) {
                curr += C[A[j]] == 0;
                C[A[j]] = 1;
                ans += curr == dis;
            }
            for(int j = i; j < n; j++) C[A[j]] = 0;
        }
        return ans;
    }
};