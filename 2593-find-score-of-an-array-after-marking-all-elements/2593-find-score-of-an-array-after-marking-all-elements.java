import java.util.PriorityQueue;
import java.util.Comparator;

class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            minHeap.offer(new int[]{nums[i], i});
        }

        long score = 0;

        while (!minHeap.isEmpty()) {
            int[] temp = minHeap.poll();
            int elem = temp[0], idx = temp[1];

            if (!visited[idx]) {
                visited[idx] = true;
                score += elem;

                if (idx - 1 >= 0 && !visited[idx - 1]) {
                    visited[idx - 1] = true;
                }
                if (idx + 1 < n && !visited[idx + 1]) {
                    visited[idx + 1] = true;
                }
            }
        }

        return score;
    }
}
