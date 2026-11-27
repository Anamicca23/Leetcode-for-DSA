class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        int n = s.length();
        char[] result = new char[n];
        int idx = 0;
        int cycleLen = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < n; j += cycleLen) {
                result[idx++] = s.charAt(j);
                int diagIndex = j + cycleLen - 2 * row;
                if (row != 0 && row != numRows - 1 && diagIndex < n) {
                    result[idx++] = s.charAt(diagIndex);
                }
            }
        }
        return new String(result);
    }
}