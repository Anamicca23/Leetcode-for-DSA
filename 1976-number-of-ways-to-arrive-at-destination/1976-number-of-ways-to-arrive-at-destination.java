import java.util.*;

class Solution {
    static final int MOD = 1_000_000_007;

    public int countPaths(int n, int[][] roads) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        for (int[] road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj.get(u).add(new int[]{v, time});
            adj.get(v).add(new int[]{u, time});
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        int[] ways = new int[n];

        pq.add(new long[]{0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.isEmpty()) {
            long[] top = pq.poll();
            long d0 = top[0];
            int i = (int) top[1];

            if (d0 > dist[i]) continue; // Skip outdated distances

            for (int[] edge : adj.get(i)) {
                int j = edge[0];
                long newD = d0 + edge[1];

                if (newD < dist[j]) {
                    dist[j] = newD;
                    ways[j] = ways[i];
                    pq.add(new long[]{newD, j});
                } else if (newD == dist[j]) {
                    ways[j] = (ways[j] + ways[i]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
}