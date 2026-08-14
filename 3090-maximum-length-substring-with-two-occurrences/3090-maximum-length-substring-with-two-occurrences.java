class Solution {
    public int maximumLengthSubstring(String s) {
        int res = 0;
        int[] fq = new int[26];

        for (int l = 0, r = 0; r < s.length(); r++) {
            fq[(s.charAt(r) & 31) - 1]++;

            while (fq[(s.charAt(r) & 31) - 1] > 2)
                fq[(s.charAt(l++) & 31) - 1]--;

            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}