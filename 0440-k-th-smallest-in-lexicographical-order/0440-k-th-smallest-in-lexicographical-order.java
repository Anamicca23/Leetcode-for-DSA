class Solution {
    // Function to calculate the gap between numbers a and b in the lexicographical tree
    private long getGap(long a, long b, long n) {
        long gap = 0;
        while (a <= n) {
            gap += Math.min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }

    // Function to find the k-th smallest number in lexicographical order
    public int findKthNumber(long n, int k) {
        long cur = 1;
        for (int i = 1; i < k;) {
            long gap = getGap(cur, cur + 1, n);
            if (i + gap <= k) {
                i += gap;
                cur++;
            } else {
                i++;
                cur *= 10;
            }
        }
        return (int) cur;
    }
}