class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        List<List<Integer>> adj = new ArrayList<>();
        boolean[] visited = new boolean[n];
        int[] ans = {0}; // Use array to store result as we need to modify it in DFS.

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        // DFS function
        class DFS {
            long dfs(int node) {
                visited[node] = true;
                long sum = values[node];
                for (int neighbor : adj.get(node)) {
                    if (!visited[neighbor]) {
                        sum += dfs(neighbor);
                        sum %= k;
                    }
                }
                if (sum % k == 0) {
                    ans[0]++;
                    return 0;
                }
                return sum;
            }
        }

        // Call DFS from root node (0)
        new DFS().dfs(0);

        return ans[0];
    }
}
