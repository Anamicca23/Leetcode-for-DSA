class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans=0
        if len(nums)%2==1:
            ans=nums[len(nums)//2]
        for i in range(len(nums)//2):
            ans+=int(str(nums[i])+str(nums[len(nums)-1-i]))
        return ans
        