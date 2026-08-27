class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        int mask = 0, bad = 0;
        for (char ch : s)
            cnt[ch - 'a']++;
        for (char ch : target)
            cnt[ch - 'a']--;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] < 0)
                bad++;
            else if (cnt[c] > 0)
                mask |= 1 << c;
        }
        for (int i = target.size() - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            cnt[cur]++;
            if (cnt[cur] == 0)
                bad--;
            else if (cnt[cur] == 1)
                mask |= 1 << cur;
            if (bad > 0)
                continue;
            int higher = mask >> (cur + 1);
            if (!higher)
                continue;
            int next = cur + 1 + __builtin_ctz(higher);
            cnt[next]--;
            string ans = target.substr(0, i);
            ans += char('a' + next);
            for (int c = 0; c < 26; c++) {
                ans.append(cnt[c], char('a' + c));
            }
            return ans;
        }
        return "";
    }
};