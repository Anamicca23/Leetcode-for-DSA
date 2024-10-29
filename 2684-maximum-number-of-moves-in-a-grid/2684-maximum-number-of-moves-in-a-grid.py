class Solution:
    def maxMoves(self, grid):
        m, n = len(grid), len(grid[0])
        res = 0
        dp = [0] * m

        for j in range(1, n):
            leftTop = 0
            found = False
            for i in range(m):
                cur = -1
                nxtLeftTop = dp[i]
                if i > 0 and leftTop != -1 and grid[i][j] > grid[i - 1][j - 1]:
                    cur = max(cur, leftTop + 1)
                if dp[i] != -1 and grid[i][j] > grid[i][j - 1]:
                    cur = max(cur, dp[i] + 1)
                if i + 1 < m and dp[i + 1] != -1 and grid[i][j] > grid[i + 1][j - 1]:
                    cur = max(cur, dp[i + 1] + 1)
                dp[i] = cur
                found = found or (dp[i] != -1)
                leftTop = nxtLeftTop
            if not found:
                break
            res = j

        return res
