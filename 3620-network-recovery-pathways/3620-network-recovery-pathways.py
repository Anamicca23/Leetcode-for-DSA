from collections import deque, defaultdict
class Solution:
    def find(self, limit, adj, online, topoSort, k):
        dist = [float('inf')] * self.n
        dist[0] = 0
        for node in topoSort:
            if dist[node] == float('inf'):
                continue
            for nxtNode, cst in adj[node]:
                if cst < limit:
                    continue
                if nxtNode != self.n - 1 and not online[nxtNode]:
                    continue
                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst)
        return dist[self.n - 1] <= k
    def findMaxPathScore(self, edges, online, k):
        self.n = len(online)
        adj = defaultdict(list)
        indegree = [0] * self.n
        low = float('inf')
        high = 0
        for u, v, cst in edges:
            adj[u].append((v, cst))
            indegree[v] += 1
            low = min(low, cst)
            high = max(high, cst)
        q = deque()
        topoSort = []
        for i in range(self.n):
            if indegree[i] == 0:
                q.append(i)
        while q:
            node = q.popleft()
            topoSort.append(node)
            for nxtNode, cst in adj[node]:
                indegree[nxtNode] -= 1
                if indegree[nxtNode] == 0:
                    q.append(nxtNode)

        res = -1
        while low <= high:
            mid = low + (high - low) // 2
            if self.find(mid, adj, online, topoSort, k):
                res = mid
                low = mid + 1
            else:
                high = mid - 1

        return res