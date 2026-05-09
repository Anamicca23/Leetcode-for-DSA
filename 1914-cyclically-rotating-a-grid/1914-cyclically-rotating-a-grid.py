class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        for offset in range(min(m, n) // 2):
            row = m - 2 * offset
            col = n - 2 * offset
            length = row * 2 + col * 2 - 4
            rot = k % length
            if rot == 0:
                continue

            ring = grid[offset][offset : n - 1 - offset]
            ring += [c[n - 1 - offset] for c in grid[offset : m - 1 - offset]]
            ring += grid[m - 1 - offset][n - 1 - offset : offset : -1]
            ring += [c[offset] for c in grid[m - 1 - offset : offset : -1]]

            ring = ring[rot:] + ring[:rot]

            idx = 0
            for j in range(offset, n - offset):
                grid[offset][j] = ring[idx]
                idx += 1
            for i in range(offset + 1, m - offset - 1):
                grid[i][n - 1 - offset] = ring[idx]
                idx += 1
            for j in range(n - offset - 1, offset - 1, -1):
                grid[m - 1 - offset][j] = ring[idx]
                idx += 1
            for i in range(m - offset - 2, offset, -1):
                grid[i][offset] = ring[idx]
                idx += 1

        return grid