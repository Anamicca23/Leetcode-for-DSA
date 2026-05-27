class Solution {
    public int numberOfSpecialChars(String word) {
        int[] lastLower = new int[26];
        int[] firstUpper = new int[26];
        Arrays.fill(lastLower, -1);
        Arrays.fill(firstUpper, -1);
        Set<Integer> invalid = new HashSet<>();
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';
                lastLower[idx] = i;
                if (firstUpper[idx] != -1) {
                    invalid.add(idx);
                }
            } else {
                int idx = ch - 'A';
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }
        int specialCount = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                !invalid.contains(i)) {
                specialCount++;
            }
        }
        return specialCount;
    }
}