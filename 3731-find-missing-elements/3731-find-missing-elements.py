class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        return (K:=set(nums)) and [x for x in range(min(K)+1, max(K)) if x not in K]