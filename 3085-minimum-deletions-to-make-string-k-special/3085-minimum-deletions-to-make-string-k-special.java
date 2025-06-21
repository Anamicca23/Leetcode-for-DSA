class Solution {
    public int minimumDeletions(String word, int k) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }

        int[] updated = new int[26];
        int size = 0;
        for (int f : freq) {
            if (f > 0) updated[size++] = f;
        }

        Arrays.sort(updated, 0, size);

        int min = 100000, totalSum = word.length(), deletedLeftSum = 0, sum = 0, j = 0;
        for (int i = 0; i < size; i++) {
            int from = updated[i], to = from + k;
            while (j < size && updated[j] <= to) {
                sum += updated[j++];
            }

            int left = size - j;
            int leftSum = totalSum - sum;
            int required = left * to;
            int deleted = leftSum - required;

            min = Math.min(min, deleted + deletedLeftSum);

            totalSum -= updated[i];
            deletedLeftSum += updated[i];
            sum -= updated[i];
        }

        return min;
    }
}