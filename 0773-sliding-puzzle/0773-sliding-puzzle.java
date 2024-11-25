import java.util.*;

class Solution {
    static int[] shift = {15, 12, 9, 6, 3, 0};
    static char[][] adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    public int slidingPuzzle(int[][] board) {
        int target = 0123450, start = 0, pos0 = -1;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) {
                int idx = i * 3 + j;
                start += (board[i][j] << shift[idx]);
                if (board[i][j] == 0) pos0 = idx;
            }
        if (start == target) return 0;

        int N = 0543211;
        BitSet viz = new BitSet(N);
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{start, pos0});

        for (int moves = 0; !q.isEmpty(); moves++) {
            int sz = q.size();
            while (sz-- > 0) {
                int[] curr = q.poll();
                int state = curr[0], p0 = curr[1];
                if (state == target) return moves;
                for (char p : adj[p0]) {
                    int s = state, B = shift[p], x = (s >> B) & 7;
                    s += -(x << B) + (x << shift[p0]);
                    if (viz.get(s)) continue;
                    q.offer(new int[]{s, p});
                    viz.set(s);
                }
            }
        }
        return -1;
    }
}
