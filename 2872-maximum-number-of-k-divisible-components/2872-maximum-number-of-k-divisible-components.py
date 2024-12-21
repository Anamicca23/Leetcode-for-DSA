from collections import defaultdict
from typing import List

class Solution:
    def __init__(self):
        self.ans = 0
        self.adj = defaultdict(list)
        self.visited = [False] * 30001

    def build_adj(self, edges: List[List[int]]) -> None:
        for i, j in edges:
            self.adj[i].append(j)
            self.adj[j].append(i)

    def dfs(self, i: int, values: List[int], k: int) -> int:
        self.visited[i] = True
        total = values[i]
        for j in self.adj[i]:
            if not self.visited[j]:
                total += self.dfs(j, values, k)
                total %= k
        if total % k == 0:
            self.ans += 1
            return 0
        return total

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        self.build_adj(edges)
        self.dfs(0, values, k)
        return self.ans
