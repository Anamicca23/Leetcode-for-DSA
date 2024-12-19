class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        if len(arr)==0:
            return 0
        
        maxm=0
        cnt = 0
        for i in range(len(arr)):
            maxm = max(arr[i],maxm)
            if(maxm==i):
               cnt+=1
        return cnt       