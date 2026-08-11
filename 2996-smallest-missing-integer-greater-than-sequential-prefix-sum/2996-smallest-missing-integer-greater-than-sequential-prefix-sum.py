class Solution:
    def missingInteger(self, nums):
        sequentialSum = nums[0]

        ##finding longest Prefix Sequential Sum
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                sequentialSum += nums[i]
            else:
                break

        hashTable = [False] * 1276

        #pulating hashTable
        for num in nums:
            hashTable[num] = True

        ##finding the missing number using ht
        while hashTable[sequentialSum]:
            sequentialSum += 1

        return sequentialSum