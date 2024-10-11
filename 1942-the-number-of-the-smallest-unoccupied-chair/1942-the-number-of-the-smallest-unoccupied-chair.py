class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        pq = []
        chairs = []
        
        targetArrival = times[targetFriend][0]
        times.sort(key=lambda x: x[0])
        
        nextChair = 0

        for arrival, leave in times:
            while pq and pq[0][0] <= arrival:
                heapq.heappush(chairs, heapq.heappop(pq)[1])
            
            if chairs:
                seat = heapq.heappop(chairs)
            else:
                seat = nextChair
                nextChair += 1
            
            heapq.heappush(pq, (leave, seat))

            if arrival == targetArrival:
                return seat
