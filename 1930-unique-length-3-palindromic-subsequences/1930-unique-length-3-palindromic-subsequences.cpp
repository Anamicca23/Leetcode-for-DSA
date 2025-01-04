class Solution {
public:
    int countPalindromicSubsequence(string s) {
        bitset<26> exist;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            int l = s.find('a' + i);
            if(l != string::npos){
                int r = s.find_last_of('a' + i);
                if(r - l < 2) continue;
                for(int k = l + 1; k < r; k++){
                    exist.set(s[k] -'a');
                    if(exist.count() == 26) break;
                }
                ans += exist.count();
                exist.reset();
            }
        }
        return ans;
    }
};