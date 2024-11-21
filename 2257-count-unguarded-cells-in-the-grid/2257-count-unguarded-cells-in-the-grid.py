class Solution:
    def mark_guarded(self, row, col, grid):
        # Mark cells in the up direction
        for i in range(row - 1, -1, -1):
            if grid[i][col] in (2, 3):
                break
            grid[i][col] = 1
        
        # Mark cells in the down direction
        for i in range(row + 1, len(grid)):
            if grid[i][col] in (2, 3):
                break
            grid[i][col] = 1
        
        # Mark cells in the left direction
        for j in range(col - 1, -1, -1):
            if grid[row][j] in (2, 3):
                break
            grid[row][j] = 1
        
        # Mark cells in the right direction
        for j in range(col + 1, len(grid[0])):
            if grid[row][j] in (2, 3):
                break
            grid[row][j] = 1

    def countUnguarded(self, m, n, guards, walls):
        grid = [[0] * n for _ in range(m)]

        # Mark guards as 2 in the grid
        for i, j in guards:
            grid[i][j] = 2
        
        # Mark walls as 3 in the grid
        for i, j in walls:
            grid[i][j] = 3
        
        # Mark guarded cells
        for i, j in guards:
            self.mark_guarded(i, j, grid)
        
        # Count unguarded cells
        return sum(1 for i in range(m) for j in range(n) if grid[i][j] == 0)
