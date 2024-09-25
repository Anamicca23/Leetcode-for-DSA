import java.util.Arrays;

class Solution {
    public int[] sumPrefixScores(String[] words) {
        int n = words.length;
        Integer[] sortedIndices = new Integer[n];
        for (int i = 0; i < n; i++) sortedIndices[i] = i;

        Arrays.sort(sortedIndices, (a, b) -> words[a].compareTo(words[b]));

        int[] commonPrefixLengths = calculateCommonPrefixLengths(words, sortedIndices);
        return calculateScores(words, sortedIndices, commonPrefixLengths);
    }

    private int[] calculateCommonPrefixLengths(String[] words, Integer[] sortedIndices) {
        int[] lengths = new int[words.length];
        for (int i = 1; i < words.length; i++) {
            String prev = words[sortedIndices[i - 1]];
            String curr = words[sortedIndices[i]];
            int commonLength = 0;
            while (commonLength < prev.length() && commonLength < curr.length() 
                   && prev.charAt(commonLength) == curr.charAt(commonLength)) {
                commonLength++;
            }
            lengths[i] = commonLength;
        }
        return lengths;
    }

    private int[] calculateScores(String[] words, Integer[] sortedIndices, int[] commonPrefixLengths) {
        int[] scores = new int[words.length];
        for (int i = 0; i < sortedIndices.length; i++) {
            int idx = sortedIndices[i];
            int len = words[idx].length();
            scores[idx] += len;
            int j = i + 1, commonLength = len;
            while (j < words.length) {
                commonLength = Math.min(commonLength, commonPrefixLengths[j]);
                if (commonLength == 0) break;
                scores[idx] += commonLength;
                scores[sortedIndices[j]] += commonLength;
                j++;
            }
        }
        return scores;
    }
}
