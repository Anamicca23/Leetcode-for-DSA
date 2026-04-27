class Solution:
    TRANS = [
        [-1, 1, -1, 3],
        [0, -1, 2, -1],
        [3, 2, -1, -1],
        [1, -1, -1, 2],
        [-1, 0, 3, -1],
        [-1, -1, 1, 0]
    ]
    DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    START = [[1, 3], [0, 2], [2, 3], [1, 2], [0, 3], [0, 1]]

    def hasValidPath(self, grid: List[List[int]]) -> bool:
        if grid[0][0] == 5: return False
        if grid[-1][-1] == 4: return False
        
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1: return True

        def check(d):
            if d == -1: return False
            r, c = self.DIRS[d]
            visit = [False] * (m * n)
            
            while 0 <= r < m and 0 <= c < n:
                cell = r * n + c
                if visit[cell]: return False
                visit[cell] = True
                
                d = self.TRANS[grid[r][c] - 1][d]
                if d == -1: return False
                if r == m - 1 and c == n - 1: return True
                
                r += self.DIRS[d][0]
                c += self.DIRS[d][1]
            return False

        s = self.START[grid[0][0] - 1]
        return check(s[0]) or check(s[1])