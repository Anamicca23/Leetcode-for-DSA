import java.util.List;

class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] apply = new int[n + 1];

        // Apply shift increments/decrements
        for (int[] shift : shifts) {
            int start = shift[0], end = shift[1] + 1, direction = shift[2] == 1 ? 1 : -1;
            apply[start] += direction;
            if (end < n) {
                apply[end] -= direction;
            }
        }

        // Compute cumulative sums for shifts
        int cumulativeShift = 0;
        char[] result = s.toCharArray();
        for (int i = 0; i < n; i++) {
            cumulativeShift += apply[i];
            int shiftedValue = ((result[i] - 'a') + cumulativeShift % 26 + 26) % 26;  // Ensure positive modulo
            result[i] = (char) ('a' + shiftedValue);
        }

        return new String(result);
    }
}
