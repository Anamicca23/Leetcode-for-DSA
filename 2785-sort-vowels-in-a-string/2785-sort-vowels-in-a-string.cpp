class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(128, 0);
        vector<bool> isVowel(128, false);

        string vowels = "aeiouAEIOU";
        for (char v : vowels) {
            isVowel[v] = true;
        }

        for (char c : s) {
            if (isVowel[c]) {
                freq[c]++;
            }
        }

        string order = "AEIOUaeiou";
        int pos = 0;

        for (char &c : s) {
            if (isVowel[c]) {
                while (pos < order.size() && freq[order[pos]] == 0) {
                    pos++;
                }
                c = order[pos];
                freq[order[pos]]--;
            }
        }

        return s;
    }
};