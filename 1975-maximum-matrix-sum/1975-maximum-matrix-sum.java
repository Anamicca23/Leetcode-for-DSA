class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;
        long totalSum = 0;
        int negativeCount = 0;
        int absMin = Integer.MAX_VALUE;

        for (int[] row : matrix) {
            for (int value : row) {
                totalSum += Math.abs(value);
                if (value < 0) {
                    negativeCount++;
                }
                absMin = Math.min(absMin, Math.abs(value));
            }
        }

        // If there are an odd number of negatives, subtract twice the smallest absolute value
        return (negativeCount % 2 == 1) ? totalSum - 2 * absMin : totalSum;
    }
}
