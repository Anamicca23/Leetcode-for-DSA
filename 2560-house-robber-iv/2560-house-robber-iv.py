class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def check(cap):
            count = taken = 0
            for x in nums:
                if taken:
                    taken = False
                elif x <= cap:
                    count += 1
                    taken = True
            return count >= k

        # Python can find min and max in list directly
        # Set the cap
        items = list(sorted(set(nums)))
        l, r = 0, len(items) - 1
        while l + 1 < r:
            mid = l + (r - l) // 2
            if check(items[mid]):
                r = mid
            else:
                l = mid + 1
        return items[l] if check(items[l]) else items[r]