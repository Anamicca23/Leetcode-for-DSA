class Solution {
    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;
        SparseTable LUT = new SparseTable(nums);

        PriorityQueue<int[]> pq = new PriorityQueue<>((num, b) -> b[0] - num[0]);
        for (int i = 0; i < n; i++)
            pq.add(new int[] { LUT.query(i, n), i, n });

        long res = 0;
        
        while (pq.peek()[0] > 0) {
            int[] top = pq.poll();
            res += top[0];
            top[2]--;
            top[0] = LUT.query(top[1], top[2]);
            pq.add(top);
            if (--k <= 0) break;
        }

        return res;
    }
}

class SparseTable {
    private final int[][] Min, Max;

    public SparseTable(int[] num) {
        int n = num.length;
        int bitWidth = 32 - Integer.numberOfLeadingZeros(n);
        Min = new int[bitWidth][n];
        Max = new int[bitWidth][n];

        for (int i = 0; i < n; i++)
            Min[0][i] = Max[0][i] = num[i];

        for (int i = 1; i < bitWidth; i++)
            for (int j = 0; j + (1 << i) <= n; j++) {
                Min[i][j] = Math.min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
                Max[i][j] = Math.max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            }
    }

    public int query(int left, int right) {
        int k = 31 - Integer.numberOfLeadingZeros(right - left);
        return Math.max(Max[k][left], Max[k][right - (1 << k)]) -
               Math.min(Min[k][left], Min[k][right - (1 << k)]);
    }
}