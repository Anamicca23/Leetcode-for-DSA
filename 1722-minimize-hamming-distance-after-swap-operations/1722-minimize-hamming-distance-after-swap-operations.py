class Solution:
    def minimumHammingDistance(self, source: list[int], target: list[int], allowedSwaps: list[list[int]]) -> int:
        n = len(source)
        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def unite(a, b):
            parent[find(a)] = find(b)

        for a, b in allowedSwaps:
            unite(a, b)
        group_freq = defaultdict(Counter)
        for i in range(n):
            group_freq[find(i)][source[i]] += 1

        hamming_distance = 0
        for i in range(n):
            root = find(i)
            if group_freq[root][target[i]] > 0:
                group_freq[root][target[i]] -= 1
            else:
                hamming_distance += 1

        return hamming_distance