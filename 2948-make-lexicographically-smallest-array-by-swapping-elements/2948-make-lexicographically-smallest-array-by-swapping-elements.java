class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        Map<Integer, List<Integer>> group = new HashMap<>();
        Map<Integer, Integer> groupId = new HashMap<>();
        Map<Integer, Integer> pos = new HashMap<>();
        int id = 1;
        group.computeIfAbsent(id, k -> new ArrayList<>()).add(sorted[0]);
        groupId.put(sorted[0], id);
        for(int i = 1; i < n; i++){
            if(sorted[i] - sorted[i - 1] > limit){
                id++;
            }
            group.computeIfAbsent(id, k -> new ArrayList<>()).add(sorted[i]);
            groupId.put(sorted[i], id);
        }
        for(int i = 0; i < n; i++){
            int grp = groupId.get(nums[i]);
            int p = pos.getOrDefault(grp, 0);
            nums[i] = group.get(grp).get(p);
            pos.put(grp, p + 1);
        }
        return nums;
    }
}