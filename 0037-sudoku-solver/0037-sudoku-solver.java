class Solution {
    // Bitmasks recording which digits are already used in each row/col/box.
    // For digit d (1..9) we use bit (d-1). A set bit means "used".
    private final int[] rowMask = new int[9];
    private final int[] colMask = new int[9];
    private final int[] boxMask = new int[9];

    // Flat list of empty cells; we’ll reorder this in-place with MRV.
    private final int[] empties = new int[81];
    private int emptyCount = 0;

    public void solveSudoku(char[][] board) {
        // Initialize masks and collect empties
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') {
                    empties[emptyCount++] = r * 9 + c;
                } else {
                    int d = ch - '1';               // 0..8
                    int bit = 1 << d;
                    rowMask[r] |= bit;
                    colMask[c] |= bit;
                    boxMask[boxIndex(r, c)] |= bit;
                }
            }
        }
        dfs(board, 0);
    }

    // Depth-first search with MRV: at step k, pick the empty with fewest options.
    private boolean dfs(char[][] board, int k) {
        if (k == emptyCount) return true; // solved

        // Choose the best (MRV) cell among k..end, swap into position k
        int bestIdx = k;
        int bestChoicesMask = 0;
        int bestChoicesCount = 10; // more than max 9

        for (int i = k; i < emptyCount; i++) {
            int pos = empties[i];
            int r = pos / 9, c = pos % 9, b = boxIndex(r, c);
            int used = rowMask[r] | colMask[c] | boxMask[b];
            int choices = (~used) & 0x1FF;              // 9 bits
            int cnt = Integer.bitCount(choices);
            if (cnt < bestChoicesCount) {
                bestChoicesCount = cnt;
                bestChoicesMask = choices;
                bestIdx = i;
                if (cnt == 1) break; // cannot get better than 1
            }
            // Early fail: if any cell has 0 options, prune immediately
            if (cnt == 0) return false;
        }

        // Swap chosen empty into slot k
        swap(empties, k, bestIdx);

        int pos = empties[k];
        int r = pos / 9, c = pos % 9, b = boxIndex(r, c);
        int choices = bestChoicesMask == 0
                ? ((~(rowMask[r] | colMask[c] | boxMask[b])) & 0x1FF)
                : bestChoicesMask;

        // Try digits by iterating set bits (low-bit trick)
        while (choices != 0) {
            int bit = choices & -choices;                  // isolate lowest 1 bit
            int d = Integer.numberOfTrailingZeros(bit);    // 0..8 for digit 1..9

            place(board, r, c, b, d, bit);
            if (dfs(board, k + 1)) return true;
            unplace(board, r, c, b, d, bit);

            choices -= bit;                                // next candidate
        }

        // Restore the order on backtrack
        swap(empties, k, k); // no-op but keeps symmetry clear
        return false;
    }

    private void place(char[][] board, int r, int c, int b, int d, int bit) {
        board[r][c] = (char) ('1' + d);
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;
    }

    private void unplace(char[][] board, int r, int c, int b, int d, int bit) {
        board[r][c] = '.';
        rowMask[r] ^= bit;
        colMask[c] ^= bit;
        boxMask[b] ^= bit;
    }

    private static int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    private static void swap(int[] a, int i, int j) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
}