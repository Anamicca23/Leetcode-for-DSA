class Solution:
    def minAbsDiff(self, grid, k):
        m, n = len(grid), len(grid[0])
        ans = [[0] * (n - k + 1) for _ in range(m - k + 1)]

        for i in range(m - k + 1):
            for j in range(n - k + 1):

                temp = []

                for x in range(i, i + k):
                    for y in range(j, j + k):
                        temp.append(grid[x][y])

                if k == 1:
                    ans[i][j] = 0
                    continue

                temp = sorted(set(temp))

                if len(temp) <= 1:
                    ans[i][j] = 0
                    continue

                mini = float('inf')
                for p in range(1, len(temp)):
                    mini = min(mini, abs(temp[p] - temp[p - 1]))

                ans[i][j] = mini

        return ans