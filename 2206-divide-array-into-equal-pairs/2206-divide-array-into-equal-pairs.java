class Solution {
        public boolean divideArray(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (!seen.add(num)) {
                seen.remove(num);
            }
        }
        return seen.isEmpty();
    }
}