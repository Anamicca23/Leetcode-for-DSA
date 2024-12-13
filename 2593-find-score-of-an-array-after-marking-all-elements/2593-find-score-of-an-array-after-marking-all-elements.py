import heapq

class Solution:
    def findScore(self, nums):
        n = len(nums)
        minheap = []
        visited = [False] * n

        # Build the min heap
        for i in range(n):
            heapq.heappush(minheap, (nums[i], i))

        score = 0

        while minheap:
            elem, idx = heapq.heappop(minheap)

            if not visited[idx]:
                visited[idx] = True
                score += elem

                if idx - 1 >= 0 and not visited[idx - 1]:
                    visited[idx - 1] = True
                if idx + 1 < n and not visited[idx + 1]:
                    visited[idx + 1] = True

        return score
