class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> freq = new HashMap<>();
        int maxlen = 0;
        for (int[] row : matrix) {
            StringBuilder pattern = new StringBuilder();
            int firstVal = row[0];
            for (int val : row) {
                pattern.append(val == firstVal ? "A" : "B");
            }
            String key = pattern.toString();
            freq.put(key, freq.getOrDefault(key, 0) + 1);
        }
        for (int count : freq.values()) {
            maxlen = Math.max(maxlen, count);
        }
        return maxlen;
    }
}
