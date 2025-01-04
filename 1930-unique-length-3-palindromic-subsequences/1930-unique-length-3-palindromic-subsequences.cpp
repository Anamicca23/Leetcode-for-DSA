class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
    
    int result = 0;
    int firstIndex[26] = {[0 ... 25] = INT_MAX};
    int lastIndex[26] = {};

    for (int i = 0; i < inputString.size(); ++i) {
        firstIndex[inputString[i] - 'a'] = min(firstIndex[inputString[i] - 'a'], i);
        lastIndex[inputString[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i)
        if (firstIndex[i] < lastIndex[i])
            result += unordered_set<char>(begin(inputString) + firstIndex[i] + 1, begin(inputString) + lastIndex[i]).size();
    return result;
}
};