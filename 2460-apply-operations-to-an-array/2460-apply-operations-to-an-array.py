class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        i=0
        while i<len(nums)-1:
            if nums[i]==nums[i+1]:
                nums[i]*=2
                nums[i+1]=0
            i+=1
        j=0
        for k in range(len(nums)):
            if nums[k]!=0:
                nums[k],nums[j]=nums[j],nums[k]
                j+=1
        return nums