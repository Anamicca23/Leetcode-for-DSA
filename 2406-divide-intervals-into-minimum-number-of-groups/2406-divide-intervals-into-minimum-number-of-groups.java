class Solution {

    public int minGroups(int[][] intervals) {
        // Find the minimum and maximum value in the intervals
        int rangeStart = Integer.MAX_VALUE;
        int rangeEnd = Integer.MIN_VALUE;
        for (int[] interval : intervals) {
            rangeStart = Math.min(rangeStart, interval[0]);
            rangeEnd = Math.max(rangeEnd, interval[1]);
        }

        // Initialize the array with all zeroes
        int[] pointToCount = new int[rangeEnd + 2];
        for (int[] interval : intervals) {
            pointToCount[interval[0]]++; // Increment at the start of the interval
            pointToCount[interval[1] + 1]--; // Decrement right after the end of the interval
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            // Update currently active intervals
            concurrentIntervals += pointToCount[i];
            maxConcurrentIntervals = Math.max(
                maxConcurrentIntervals,
                concurrentIntervals
            );
        }

        return maxConcurrentIntervals;
    }
}