import java.util.PriorityQueue;

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int num : nums) {
            pq.add((long) num);
        }
        long cnt = 0;
        while (pq.peek() < k) {
            long first = pq.poll();
            long second = pq.poll();
            long num = 2 * Math.min(first, second) + Math.max(first, second);
            pq.add(num);
            cnt++;
        }
        return (int) cnt;
    }
}