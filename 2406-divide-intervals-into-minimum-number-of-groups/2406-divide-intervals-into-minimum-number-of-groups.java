class Solution {
    public int minGroups(int[][] intervals) {
        // Sort intervals based on start time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // Priority queue (min-heap) to track the end times
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If the current interval can fit in an existing group (smallest end time <= start time)
            if (!pq.isEmpty() && start > pq.peek()) {
                pq.poll();  // Reuse the group
            }

            // Push the current end time to the heap
            pq.offer(end);
        }

        // The size of the priority queue represents the number of groups needed
        return pq.size();
    }
}