class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        int prev1[] = new int[n+1];
        int prev2[] = new int[n+1];
        for(int i=0;i<n+1;i++){
            prev1[i] = prev2[i] = -1;
        }
        
        for(int i=0;i<n;i++){
            int value = nums[i];
            if(prev2[value] != -1){
                ans = Math.min(ans, (i-prev2[value]));
            }
            prev2[value] = prev1[value];
            prev1[value] = i;
        }
        return (ans==Integer.MAX_VALUE)? -1: 2*ans;
    }
}