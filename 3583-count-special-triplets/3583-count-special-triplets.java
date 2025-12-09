class Solution {
    public int specialTriplets(int[] nums) {
        int n = 100001, mod = 1000000007;
        long ans = 0;
        int[] hash = new int[n], prev = new int[n];
        for(int i = 0; i < nums.length; i++) hash[nums[i]]++;
        for(int i = 1; i < nums.length - 1; i++) {
            prev[nums[i - 1]]++;
            int j = nums[i], k = 2*j;
            if(k < n) {
                ans += (long)prev[k] * (hash[k] - prev[k] - (j == 0 ? 1 : 0));
            }
        }
        return (int)(ans % mod);
    }
}