class Solution {
public:
    int numSub(string s) {
        const int MOD = 1000000007;
        long long cur = 0, ans = 0;
        for(char c: s){
            if(c == '1') cur = (cur + 1) % MOD;
            else cur = 0;
            ans = (ans + cur) % MOD;
        }
        return (int)ans;
    }
};