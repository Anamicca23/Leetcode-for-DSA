import java.util.*;

class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> chairs = new PriorityQueue<>();
        
        int targetArrival = times[targetFriend][0];
        Arrays.sort(times, Comparator.comparingInt(a -> a[0]));

        int nextChair = 0, seat = 0;

        for (int[] time : times) {
            int arrival = time[0], leave = time[1];

            // Free up chairs of friends who have already left
            while (!pq.isEmpty() && pq.peek()[0] <= arrival) {
                chairs.offer(pq.poll()[1]);
            }

            // Assign the smallest available chair
            if (!chairs.isEmpty()) seat = chairs.poll();
            else seat = nextChair++;

            pq.offer(new int[] {leave, seat});

            // If this is the target friend, return their seat
            if (arrival == targetArrival) break;
        }

        return seat;
    }
}
