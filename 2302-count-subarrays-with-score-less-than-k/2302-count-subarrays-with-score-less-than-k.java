class Solution {
    public long countSubarrays(int[] nums, long k) {
        
        long total =0 ;
        long count=0;
        for (int start=0,end =0 ; end <nums.length;end++){

            total += nums[end];

            while (start<=end && total*(end-start+1)>=k){
                total -=nums[start];
                start++;
            }
            count += end -start+1;

        }
        return count;

    }
}