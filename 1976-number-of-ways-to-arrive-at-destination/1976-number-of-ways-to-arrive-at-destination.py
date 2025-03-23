import heapq

class Solution:
    MOD = 10**9 + 7

    def countPaths(self, n: int, roads: list[list[int]]) -> int:
        from collections import defaultdict
        
        adj = defaultdict(list)
        for u, v, time in roads:
            adj[u].append((time, v))
            adj[v].append((time, u))
        
        pq = [(0, 0)]  # (distance, node)
        dist = [float('inf')] * n
        ways = [0] * n
        dist[0] = 0
        ways[0] = 1

        while pq:
            d0, i = heapq.heappop(pq)

            if d0 > dist[i]: continue  # Ignore outdated distances

            for d2, j in adj[i]:
                newD = d0 + d2
                
                if newD < dist[j]:  
                    dist[j] = newD
                    ways[j] = ways[i]
                    heapq.heappush(pq, (newD, j))
                elif newD == dist[j]:
                    ways[j] = (ways[j] + ways[i]) % self.MOD
        
        return ways[n - 1]