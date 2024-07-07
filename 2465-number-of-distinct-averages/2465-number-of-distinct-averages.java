class Solution {
    public int distinctAverages(int[] nums) {
        Set<Double> st= new HashSet<>();
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=0; i<n/2;i++){
            int sum = (nums[i]+ nums[n-i-1]);
            st.add((double)(sum)/2.0);
        }
        return st.size();
    }
}