class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int maxNum = 0;
        for(int num:nums){
            maxNum = Math.max(maxNum,num);
        }
        int[] counts = new int[maxNum+1];
        int dupCount=0;
        long totalSum=0;
        long curSum =0;
        for(int i =0;i<k;i++){
            if(counts[nums[i]]>=1){
                dupCount++;
            }
            counts[nums[i]]++;
            curSum+= nums[i];
        }
        if(dupCount==0){
            totalSum=curSum;
        }
        for(int i =k;i<nums.length;i++){
            if(counts[nums[i]]>=1){
                dupCount++;
            }
            counts[nums[i]]++;
            curSum+= nums[i];  
            if(counts[nums[i-k]]>1){
                dupCount--;
            }
            counts[nums[i-k]]--;
            curSum-=nums[i-k];
            if(dupCount==0){
                totalSum = Math.max(totalSum,curSum);
            } 
        }
        return totalSum;
    }
}