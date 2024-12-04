class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        if (str2.length() > str1.length()) {
            return false;
        }
        int test = 0;
        for (int i = 0; i < str1.length() && test < str2.length(); i++) {
            if (str1.charAt(i) == str2.charAt(test)) {
                test++;
            } else if (((str1.charAt(i) - 'a') + 1) % 26 + 'a' == str2.charAt(test)) {
                test++;
            }
        }
        return test == str2.length();
    }
}
