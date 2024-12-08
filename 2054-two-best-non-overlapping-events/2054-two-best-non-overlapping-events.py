import heapq

class Solution:
    def maxTwoEvents(self, events):
        events.sort()
        pq = []
        max_val = 0
        ans = 0

        for start, end, value in events:
            while pq and pq[0][0] < start:
                max_val = max(max_val, heapq.heappop(pq)[1])
            ans = max(ans, max_val + value)
            heapq.heappush(pq, (end, value))

        return ans