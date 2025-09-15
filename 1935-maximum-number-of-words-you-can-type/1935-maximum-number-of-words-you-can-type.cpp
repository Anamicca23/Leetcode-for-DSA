class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> brokenKeyMap(26, 0);
        int asciiA = 'a';

        // Mark broken keys
        for (char c : brokenLetters) {
            brokenKeyMap[c - asciiA] = 1;
        }

        int wordCount = 1;  // words separated by spaces
        int brokenWordCount = 0;
        bool wordHasBrokenKey = false;

        for (char c : text) {
            if (c == ' ') {
                if (wordHasBrokenKey) brokenWordCount++;
                wordHasBrokenKey = false;
                wordCount++;
            } else if (!wordHasBrokenKey && brokenKeyMap[c - asciiA] > 0) {
                wordHasBrokenKey = true;
            }
        }

        if (wordHasBrokenKey) brokenWordCount++;

        return wordCount - brokenWordCount;
    }
};