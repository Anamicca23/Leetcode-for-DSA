class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int[] cnt = new int[26];
        for (char ch : s.toCharArray()) cnt[ch - 'a']++;
        for (char ch : target.toCharArray()) cnt[ch - 'a']--;
        int bad = 0, mx = -1;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] < 0) bad++;
            if (cnt[c] > 0) mx = c;
        }
        for (int i = target.length() - 1; i >= 0; i--) {
            int cur = target.charAt(i) - 'a';
            cnt[cur]++;
            if (cnt[cur] == 0) bad--;
            else if (cnt[cur] == 1) mx = Math.max(mx, cur);
            if (bad > 0 || mx <= cur) continue;
            int next = cur + 1;
            while (cnt[next] == 0) next++;
            cnt[next]--;
            StringBuilder ans = new StringBuilder(target.substring(0, i));
            ans.append((char) ('a' + next));
            for (int c = 0; c < 26; c++) {
                while (cnt[c]-- > 0) {
                    ans.append((char) ('a' + c));
                }
            }
            return ans.toString();
        }
        return "";
    }
}