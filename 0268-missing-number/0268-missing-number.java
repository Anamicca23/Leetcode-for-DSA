class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int res =n;
        for(int i=0; i<n;i++){
               res^=i;
               res^=nums[i];
        }
        return res;
    }
}