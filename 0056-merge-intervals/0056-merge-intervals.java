class Solution {
    public int[][] merge(int[][] in) {
        Arrays.sort(in, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> ans = new ArrayList<>();
        ans.add(in[0]);
        for (int[] it : in) {
            int[] last = ans.get(ans.size() - 1);
            if (last[1] < it[0]) ans.add(it);
            else last[1] = Math.max(last[1], it[1]);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
