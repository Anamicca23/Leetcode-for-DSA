class Solution {
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();
        for (int i = 1; i < n - 1; i++) {
            if (sentence.charAt(i) == ' ' && sentence.charAt(i - 1) != sentence.charAt(i + 1)) {
                return false;
            }
        }
        return sentence.charAt(0) == sentence.charAt(n - 1);
    }
}
