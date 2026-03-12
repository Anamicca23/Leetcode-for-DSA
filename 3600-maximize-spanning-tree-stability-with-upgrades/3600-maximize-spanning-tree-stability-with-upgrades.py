class Solution(object):
    def maxStability(self, n, edges, k):
        parent = list(range(n))
        size = [1] * n
        components = [n]
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(u,v):
            pu = find(u)
            pv = find(v)
            if pu == pv:
                return False
            components[0] -= 1
            if size[pu] > size[pv]:
                parent[pv] = pu
                size[pu] += size[pv]
            else:
                parent[pu] = pv
                size[pv] += size[pu]

            return True
        must = []
        flex = []
        for e in edges:
            if e[3] == 1:
                must.append(e)
            else:
                flex.append(e)

        mini = float('inf')

        for u,v,w,t in must:
            mini = min(mini,w)
            if not union(u,v):
                return -1

        flex.sort(key=lambda x: -x[2])
        import heapq
        pq = []
        for u,v,w,t in flex:
            if union(u,v):
                heapq.heappush(pq,w)
        while k > 0 and pq:
            x = heapq.heappop(pq)
            mini = min(mini, 2*x)
            k -= 1
        if components[0] != 1:
            return -1
        if pq:
            return min(mini, pq[0])
        return mini