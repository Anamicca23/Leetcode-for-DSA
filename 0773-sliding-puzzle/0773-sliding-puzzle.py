from collections import deque

adj = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
shift = [15, 12, 9, 6, 3, 0]

class Solution:
    def slidingPuzzle(self, board):
        target, start, pos0 = 0o123450, 0, -1
        for i in range(2):
            for j in range(3):
                idx = i * 3 + j
                start += (board[i][j] << shift[idx])
                if board[i][j] == 0:
                    pos0 = idx

        if start == target:
            return 0

        N = 0o543211
        viz = [False] * N
        q = deque([(start, pos0)])

        for moves in range(N):
            for _ in range(len(q)):
                state, p0 = q.popleft()
                if state == target:
                    return moves
                for p in adj[p0]:
                    s, B = state, shift[p]
                    x = (s >> B) & 7
                    s += -(x << B) + (x << shift[p0])
                    if viz[s]:
                        continue
                    q.append((s, p))
                    viz[s] = True
        return -1
