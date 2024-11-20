class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> d(3), h(3);
        for (char c : s) d[c-'a']++;
        for (int i = 0; i < 3; i++) if ((d[i] -= k) < 0) return -1;
        
        int m = 0, l = 0;
        for (int r = 0; r < s.length(); r++) {
            h[s[r]-'a']++;
            while (l <= r && h[s[r]-'a'] > d[s[r]-'a']) h[s[l++]-'a']--;
            m = max(m, r - l + 1);
        }
        return s.length() - m;
    }
};