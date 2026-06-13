class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (const string& word : words) {
            int sumWeight = 0;
            for (char ch : word) {
                sumWeight += weights[ch - 'a'];
            }
            int value = sumWeight % 26;   
            result.push_back(char('z' - value));
        }
        return result;
    }
};