class Solution {
    public int[] productQueries(int n, int[][] queries) {
        final int MOD = 1000000007;
        List<Integer> powers = new ArrayList<>();
        while (n > 0) {
            int lowBit = n & -n;
            powers.add(lowBit);
            n ^= lowBit;
        }
        int size = powers.size();
        int[][] table = new int[size][size];
        for (int row = 0; row < size; row++) {
            table[row][row] = powers.get(row);
            for (int col = row + 1; col < size; col++) {
                table[row][col] = (int)((long)table[row][col - 1] * powers.get(col) % MOD);
            }
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int p = queries[i][0];
            int q = queries[i][1];
            result[i] = table[p][q];
        }
        return result;
    }
}