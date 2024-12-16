import heapq

class Solution:
    def getFinalState(self, nums: list[int], k: int, multiplier: int) -> list[int]:
        heap = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(heap)  # Convert to min-heap

        for _ in range(k):
            num, idx = heapq.heappop(heap)  # Pop the smallest element
            nums[idx] = num * multiplier   # Update the value in nums
            heapq.heappush(heap, (nums[idx], idx))  # Push the updated pair back into the heap

        return nums
