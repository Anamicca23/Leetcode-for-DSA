import java.util.*;

class Solution {
    int n;
    public boolean find(int limit, List<List<int[]>> adj,
                        boolean[] online, List<Integer> topoSort, long k) {
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        for (int node : topoSort) {
            if (dist[node] == Long.MAX_VALUE) continue;
            for (int[] nxt : adj.get(node)) {
                int nxtNode = nxt[0];
                int cst = nxt[1];
                if (cst < limit) continue;
                if (nxtNode != n - 1 && !online[nxtNode]) continue;
                dist[nxtNode] = Math.min(dist[nxtNode], dist[node] + cst);
            }
        }
        return dist[n - 1] <= k;
    }

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        n = online.length;
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        int[] indegree = new int[n];
        int low = Integer.MAX_VALUE;
        int high = 0;
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int cst = e[2];
            adj.get(u).add(new int[]{v, cst});
            indegree[v]++;
            low = Math.min(low, cst);
            high = Math.max(high, cst);
        }
        Queue<Integer> q = new LinkedList<>();
        List<Integer> topoSort = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int node = q.poll();
            topoSort.add(node);
            for (int[] ngbr : adj.get(node)) {
                int nxtNode = ngbr[0];
                indegree[nxtNode]--;
                if (indegree[nxtNode] == 0) {
                    q.offer(nxtNode);
                }
            }
        }
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (find(mid, adj, online, topoSort, k)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
}