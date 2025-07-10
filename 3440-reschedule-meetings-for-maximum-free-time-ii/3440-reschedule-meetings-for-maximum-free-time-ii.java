class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        if (n == 0) return eventTime;

        int[] gaps = new int[n + 1];
        gaps[0] = startTime[0];

        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        int[] largestRight = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            largestRight[i] = Math.max(largestRight[i + 1], gaps[i + 1]);
        }

        int maxFree = 0, largestLeft = 0;
        for (int i = 1; i <= n; i++) {
            int duration = endTime[i - 1] - startTime[i - 1];
            boolean canFitLeft = largestLeft >= duration;
            boolean canFitRight = largestRight[i] >= duration;

            if (canFitLeft || canFitRight) {
                int merged = gaps[i - 1] + gaps[i] + duration;
                maxFree = Math.max(maxFree, merged);
            }

            maxFree = Math.max(maxFree, gaps[i - 1] + gaps[i]);
            largestLeft = Math.max(largestLeft, gaps[i - 1]);
        }

        return maxFree;
    }
}