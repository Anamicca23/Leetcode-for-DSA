import heapq
class Solution:
    def minNumberOfSeconds(self, h, t):
        pq = []
        for i in range(len(t)):
            heapq.heappush(pq, (t[i], i, 1))
        res = 0
        while h > 0:
            tm, idx, x = heapq.heappop(pq)
            res = tm
            h -= 1
            if h > 0:
                nx = x + 1
                nt = t[idx] * (nx * (nx + 1) // 2)
                heapq.heappush(pq, (nt, idx, nx))
        return res