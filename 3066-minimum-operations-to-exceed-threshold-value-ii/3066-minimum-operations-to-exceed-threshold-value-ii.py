import heapq

class Solution:
    def minOperations(self, nums, k):
        heapq.heapify(nums)
        cnt = 0
        while nums[0] < k:
            first = heapq.heappop(nums)
            second = heapq.heappop(nums)
            num = 2 * min(first, second) + max(first, second)
            heapq.heappush(nums, num)
            cnt += 1
        return cnt