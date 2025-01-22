class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        height = [[-1] * n for _ in range(m)]
        q = deque()
        
        # Initialize water cells
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    height[i][j] = 0
                    q.append((i, j))
        
        # BFS directions
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]
        
        # BFS from water to land
        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and height[nx][ny] == -1:
                    height[nx][ny] = height[x][y] + 1
                    q.append((nx, ny))
        
        return height