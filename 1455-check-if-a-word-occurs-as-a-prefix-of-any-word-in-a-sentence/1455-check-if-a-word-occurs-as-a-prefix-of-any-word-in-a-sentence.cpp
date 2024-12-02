class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);

        string token = "";
        int index = 1;
        while(getline(ss, token, ' ')) {
            if(token.find(searchWord, 0) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};