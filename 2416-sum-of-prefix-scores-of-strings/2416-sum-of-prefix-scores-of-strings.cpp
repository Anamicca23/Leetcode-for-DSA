class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> sortedIndices(n);
        for (int i = 0; i < n; i++) sortedIndices[i] = i;

        sort(sortedIndices.begin(), sortedIndices.end(), [&words](int a, int b) {
            return words[a] < words[b];
        });

        vector<int> commonPrefixLengths = calculateCommonPrefixLengths(words, sortedIndices);
        return calculateScores(words, sortedIndices, commonPrefixLengths);
    }

private:
    vector<int> calculateCommonPrefixLengths(const vector<string>& words, const vector<int>& sortedIndices) {
        vector<int> lengths(words.size(), 0);
        for (int i = 1; i < words.size(); i++) {
            const auto& prev = words[sortedIndices[i - 1]], &curr = words[sortedIndices[i]];
            int commonLength = 0;
            while (commonLength < prev.length() && commonLength < curr.length() && prev[commonLength] == curr[commonLength]) {
                commonLength++;
            }
            lengths[i] = commonLength;
        }
        return lengths;
    }

    vector<int> calculateScores(const vector<string>& words, const vector<int>& sortedIndices, const vector<int>& commonPrefixLengths) {
        vector<int> scores(words.size(), 0);
        for (int i = 0; i < sortedIndices.size(); i++) {
            int idx = sortedIndices[i], len = words[idx].length();
            scores[idx] += len;
            int j = i + 1, commonLength = len;
            while (j < words.size()) {
                commonLength = std::min(commonLength, commonPrefixLengths[j]);
                if (commonLength == 0) break;
                scores[idx] += commonLength;
                scores[sortedIndices[j]] += commonLength;
                j++;
            }
        }
        return scores;
    }
};
