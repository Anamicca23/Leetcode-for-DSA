class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long m=0;
        if(nums.length==1)
        {
            return (long)(nums[0]);
        }
        for(int i=0,j=nums.length-1;i<j;i++,j--)
        {
            String p=String.valueOf(nums[i])+String.valueOf(nums[j]);
            long q=Long.parseLong(p);
            m+=q;
        }
        if(nums.length%2==1)
        {
            return m+(long)(nums[nums.length/2]);
        }
        return m;
    }
}