class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        if len(nums)==1: return 1
        xMax=max(nums)
        freq=[0]*(1+xMax)
        for x in nums:
            freq[x]+=1
        par, x=0, 0
        while x<=xMax:
            while x<=xMax and freq[x]==0:
                x+=1
            if x>xMax: break
            end=x+k
            par+=1
            x=end+1
        return par
        