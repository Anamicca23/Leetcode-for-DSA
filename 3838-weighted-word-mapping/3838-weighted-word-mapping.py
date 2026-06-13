class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        result = []
        for word in words:
            sum_weight = 0
            for ch in word:
                sum_weight += weights[ord(ch) - ord('a')]
            value = sum_weight % 26
            result.append(chr(ord('z') - value))
        return "".join(result)