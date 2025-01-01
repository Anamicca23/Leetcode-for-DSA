class Solution {
    public int maxScore(String s) {
        int ret = 0;
        int n = s.length();
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) v[i] += v[i - 1];
            v[i] += s.charAt(i) == '0' ? 1 : 0;
        }
        int one = 0;
        for (int i = n - 1; i >= 1; i--) {
            one += s.charAt(i) == '1' ? 1 : 0;
            ret = Math.max(ret, v[i - 1] + one);
        }
        return ret;
    }
}
