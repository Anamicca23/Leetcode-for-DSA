class Solution:
    def countSubmatrices(self, grid: list[list[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        px = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                px[i+1][j+1] = grid[i][j] + px[i][j+1] + px[i+1][j] - px[i][j]
                if px[i+1][j+1] <= k:
                    ans += 1
        return ans