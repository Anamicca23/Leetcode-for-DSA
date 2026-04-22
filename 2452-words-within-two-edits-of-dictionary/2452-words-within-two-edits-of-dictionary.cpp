class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,vector<string>& dictionary) {
        auto hamming = [](string& s1, string& s2) -> int {
            int h = 0;
            for (int i = 0; i < s1.size(); ++i)
                h += s1[i] != s2[i];
            return h;
        };

        vector<string> words;
        for (string& q : queries)
            for (string& d : dictionary)
                if (hamming(q, d) <= 2) {
                    words.push_back(q);
                    break;
                }

        return words;
    }
};