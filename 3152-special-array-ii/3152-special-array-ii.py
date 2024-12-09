class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n=len(nums)
        prev=nums[0]&1
        sameParity=[0]*n
        j=0
        for i in range(n):
            x=nums[i]&1
            if x==prev: j+=1
            sameParity[i]=j
            prev=x
        m=len(queries)
        ans=[False]*m
        for i, (s, t) in enumerate(queries):
            ans[i]=(sameParity[s]==sameParity[t])
        return ans
        