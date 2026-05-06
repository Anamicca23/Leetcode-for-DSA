class Solution:
    def rotateTheBox(self, grid: List[List[str]]) -> List[List[str]]:
        rows, cols = len(grid), len(grid[0])
        for r in range(rows):
            p = 0
            for c in range(cols):
                if grid[r][c] == '.':
                    grid[r][c], grid[r][p] = grid[r][p], grid[r][c]
                    p += 1
                elif grid[r][c] == '*':
                    p = c + 1
        
        res = [[''] * rows for _ in range(cols)]
        for r in range(rows):
            for c in range(cols):
                res[c][rows - 1 - r] = grid[r][c]
                
        return res