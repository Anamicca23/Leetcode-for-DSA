class Solution {
    private int[] parent;

    private int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    private void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int[] swap : allowedSwaps)
            unite(swap[0], swap[1]);

        Map<Integer, Map<Integer, Integer>> groupFreq = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = find(i);
            groupFreq.computeIfAbsent(root, k -> new HashMap<>())
                     .merge(source[i], 1, Integer::sum);
        }

        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            Map<Integer, Integer> freq = groupFreq.get(root);
            if (freq.getOrDefault(target[i], 0) > 0)
                freq.merge(target[i], -1, Integer::sum);
            else
                hammingDistance++;
        }

        return hammingDistance;
    }
}