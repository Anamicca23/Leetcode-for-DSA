class Solution {
    public int minimumPushes(String word) {
        int minPushCount = 0;

        int[] charCount = new int[26];

        for (int i = 0; i < word.length(); i++) {
            charCount[word.charAt(i) - 'a']++;
        }

        charCount = Arrays.stream(charCount)
                .boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(i -> i)
                .toArray();

        for (int i = 0; i < charCount.length; i++) {
            minPushCount += charCount[i] * (i / 8 + 1);
        }

        return minPushCount;
    }
}