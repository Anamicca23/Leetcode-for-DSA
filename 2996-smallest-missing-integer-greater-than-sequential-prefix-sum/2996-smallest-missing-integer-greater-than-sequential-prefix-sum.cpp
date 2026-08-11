class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sequentialSum = nums[0];

        //finding longest Prefix Sequential Sum
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1)
                sequentialSum += nums[i];
            else
                break;
        }

        vector<bool> hashTable(1276, false);

        //pulating hashTable
        for(int num : nums)
            hashTable[num] = true;

        //finding the missing number using ht
        while(hashTable[sequentialSum])
            sequentialSum++;

        return sequentialSum;
    }
};