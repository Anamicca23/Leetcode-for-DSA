import java.util.*;

class Solution {
    public List<int[]> validArrangement(int[][] pairs) {
        // Graph adjacency list and degree tracker
        Map<Integer, LinkedList<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> inOutDeg = new HashMap<>();

        // Build graph and track in/out degrees
        for (int[] pair : pairs) {
            int start = pair[0], end = pair[1];
            graph.computeIfAbsent(start, k -> new LinkedList<>()).add(end);
            inOutDeg.put(start, inOutDeg.getOrDefault(start, 0) + 1); // Out-degree
            inOutDeg.put(end, inOutDeg.getOrDefault(end, 0) - 1);    // In-degree
        }

        // Find the start node
        int startNode = pairs[0][0];
        for (int node : inOutDeg.keySet()) {
            if (inOutDeg.get(node) == 1) {
                startNode = node;
                break;
            }
        }

        // Hierholzer's algorithm
        LinkedList<int[]> path = new LinkedList<>();
        dfs(startNode, graph, path);

        // Convert LinkedList to List and return
        return path;
    }

    private void dfs(int curr, Map<Integer, LinkedList<Integer>> graph, LinkedList<int[]> path) {
        LinkedList<Integer> neighbors = graph.getOrDefault(curr, new LinkedList<>());
        while (!neighbors.isEmpty()) {
            int next = neighbors.poll();
            dfs(next, graph, path);
            path.addFirst(new int[]{curr, next}); // Add to path in reverse order
        }
    }
}