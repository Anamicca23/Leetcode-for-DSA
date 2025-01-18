import java.util.*;

class Solution {
    public int minCost(int[][] g) {
        int n = g.length, m = g[0].length;
        int[][] d = new int[n][m];
        for (int[] row : d) Arrays.fill(row, Integer.MAX_VALUE);
        int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        Deque<int[]> q = new ArrayDeque<>();
        q.offerFirst(new int[]{0, 0});
        d[0][0] = 0;

        while (!q.isEmpty()) {
            int[] cur = q.pollFirst();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i], w = (i + 1 != g[x][y]) ? 1 : 0;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && d[nx][ny] > d[x][y] + w) {
                    d[nx][ny] = d[x][y] + w;
                    if (w == 1) q.offerLast(new int[]{nx, ny});
                    else q.offerFirst(new int[]{nx, ny});
                }
            }
        }
        return d[n - 1][m - 1];
    }
}
