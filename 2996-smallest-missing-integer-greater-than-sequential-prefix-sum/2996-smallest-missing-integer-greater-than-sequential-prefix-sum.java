class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;

        boolean[] hashTable = new boolean[1276];

        int sequentialSum = nums[0];

        //populating hashTable
        for(int i = 0; i < n; i++){
            hashTable[nums[i]] = true;
        }

        //finding longest Prefix Sequential Sum
        for(int i = 1;
            i < n && nums[i] == nums[i - 1] + 1;
            sequentialSum += nums[i++]);

        //finding the missing number using ht
        while(hashTable[sequentialSum])
            sequentialSum++;
            

        return sequentialSum;
    }
}