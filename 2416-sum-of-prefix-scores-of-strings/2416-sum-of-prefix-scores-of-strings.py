class Solution:
    def sumPrefixScores(self, words):
        n = len(words)
        sorted_indices = list(range(n))
        
        sorted_indices.sort(key=lambda x: words[x])
        
        common_prefix_lengths = self.calculateCommonPrefixLengths(words, sorted_indices)
        return self.calculateScores(words, sorted_indices, common_prefix_lengths)

    def calculateCommonPrefixLengths(self, words, sorted_indices):
        lengths = [0] * len(words)
        for i in range(1, len(words)):
            prev = words[sorted_indices[i - 1]]
            curr = words[sorted_indices[i]]
            common_length = 0
            while (common_length < len(prev) and 
                   common_length < len(curr) and 
                   prev[common_length] == curr[common_length]):
                common_length += 1
            lengths[i] = common_length
        return lengths

    def calculateScores(self, words, sorted_indices, common_prefix_lengths):
        scores = [0] * len(words)
        for i in range(len(sorted_indices)):
            idx = sorted_indices[i]
            length = len(words[idx])
            scores[idx] += length
            j = i + 1
            common_length = length
            while j < len(words):
                common_length = min(common_length, common_prefix_lengths[j])
                if common_length == 0:
                    break
                scores[idx] += common_length
                scores[sorted_indices[j]] += common_length
                j += 1
        return scores
