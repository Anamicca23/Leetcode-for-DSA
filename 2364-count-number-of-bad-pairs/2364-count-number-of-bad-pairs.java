class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        long totalBadPairs = (1L * n *(n-1)) /2;
        long goodPair =0 ;
         HashMap<Integer,Integer> mp= new HashMap<>();
        for (int i =0 ; i  < n ; i++){
           int prev = mp.getOrDefault(i-nums[i],0);

            goodPair+= prev;
            mp.put(i-nums[i],prev+1);
        }

        return totalBadPairs - goodPair;
    }
}