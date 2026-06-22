class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (char c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                freq[c]++;
            }
        }
        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l'] / 2;
        int o = freq['o'] / 2;
        int n = freq['n'];
        return min({b, a, l, o, n});
    }
};