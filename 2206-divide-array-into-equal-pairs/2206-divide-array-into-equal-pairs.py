class Solution:
        def divideArray(self, nums: List[int]) -> bool:
            seen = set()
            for num in nums:
                if num in seen:
                    seen.discard(num)
                else:
                    seen.add(num)
            return not seen    