class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        parents = [i for i in range(n)]
        rank = [1] * n
        minCost = [131071] * n

        def find(v):
            p = parents[v]
            while v != p:
                p, v = parents[p], p
            return p 

        def union(u, v, w):
            p1, p2 = find(u), find(v)                        
            minCost[p1] &= w & minCost[p2]
            minCost[p2] = minCost[p1]

            if p1 != p2: 
                if rank[p1] >= rank[p2]:
                    parents[p2] = p1 
                    rank[p1] += rank[p2]
                else:
                    parents[p1] = p2
                    rank[p2] += rank[p1]                                                
            else:
                return 

        for u, v, w in edges:
            union(u, v, w)     
        
        res = []
        for u, v in query:
            p1, p2 = find(u), find(v)
            if p1 == p2 and minCost[p1] != 131071:
                res.append(minCost[p1])
            else:
                res.append(-1)

        return res