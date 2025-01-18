from collections import deque

class Solution:
    def minCost(self, g: list[list[int]]) -> int:
        n, m = len(g), len(g[0])
        d = [[float('inf')] * m for _ in range(n)]
        dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
        q = deque([(0, 0)])
        d[0][0] = 0

        while q:
            x, y = q.popleft()
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                w = int(i + 1 != g[x][y])
                if 0 <= nx < n and 0 <= ny < m and d[nx][ny] > d[x][y] + w:
                    d[nx][ny] = d[x][y] + w
                    if w == 1:
                        q.append((nx, ny))
                    else:
                        q.appendleft((nx, ny))
        return d[n - 1][m - 1]
