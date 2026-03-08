class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        l=[]
        for i in range(len(nums)):
            if nums[i][i]=='0':
                l.append('1')
            else:
                l.append('0')
        return ''.join(l)