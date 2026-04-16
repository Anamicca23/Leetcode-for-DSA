class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        Map<Integer, Integer> lastSeen = new HashMap<>(), rightSeen = new HashMap<>();
        List<Integer> dist = new ArrayList<>(), ans = new ArrayList<>();
        for (int i = 0, n = nums.length; i < nums.length * 2; ++i) {
            if (i < n)
                dist.add(n + 1);
            if (lastSeen.containsKey(nums[i % n])) {
                int curInd = i % n;
                dist.set(curInd, Math.min(dist.get(curInd), i - lastSeen.get(nums[curInd])));
            }
            lastSeen.put(nums[i % n], i);
        }
        for (int i = nums.length * 2 - 1, n = nums.length; i >= 0; --i) {
            if (rightSeen.containsKey(nums[i % n])) {
                int curInd = i % n;
                dist.set(curInd, Math.min(dist.get(curInd), rightSeen.get(nums[curInd]) - i));
            }
            rightSeen.put(nums[i % n], i);
        }
        for (int q : queries)
            ans.add((dist.get(q) >= nums.length) ? -1 : dist.get(q));
        return ans;
    }
}