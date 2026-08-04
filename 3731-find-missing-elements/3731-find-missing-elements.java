class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        boolean[] lookup = new boolean[101]; 
        int lg = 0, sm = 101; 
        for(int i = 0; i < nums.length; i++) {
            sm = Math.min(sm, nums[i]);
            lg = Math.max(lg, nums[i]);  
            lookup[nums[i]] = true; 
        }
        List<Integer> ans = new ArrayList<>(); 
        for(int i = sm; i <= lg; i++) if(!lookup[i]) ans.add(i); 
        return ans; 
    }
}