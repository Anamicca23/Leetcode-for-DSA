class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder result = new StringBuilder();
        for (String word : words) {
            int sumWeight = 0;
            for (char ch : word.toCharArray()) {
                sumWeight += weights[ch - 'a'];
            }
            int value = sumWeight % 26;
            result.append((char)('z' - value));
        }
        return result.toString();
    }
}