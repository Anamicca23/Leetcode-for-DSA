from typing import List
from collections import deque


class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m = len(classroom)
        n = len(classroom[0])
        NS = m * n
        flat = []
        for row in classroom:
            flat.extend(row)
        litbit = [0] * NS
        nlit = 0
        start = 0
        for p in range(NS):
            c = flat[p]
            if c == 'S':
                start = p
            elif c == 'L':
                litbit[p] = 1 << nlit
                nlit += 1
        if nlit == 0:
            return 0
        full = (1 << nlit) - 1
        M = 1 << nlit

        blocked = [c == 'X' for c in flat]
        isR = [c == 'R' for c in flat]

        adj = []
        for p in range(NS):
            i, j = divmod(p, n)
            nb = []
            if i > 0 and not blocked[p - n]:
                nb.append(p - n)
            if i < m - 1 and not blocked[p + n]:
                nb.append(p + n)
            if j > 0 and not blocked[p - 1]:
                nb.append(p - 1)
            if j < n - 1 and not blocked[p + 1]:
                nb.append(p + 1)
            adj.append(nb)

        best = [-1] * (NS * M)
        e0 = energy
        if isR[start]:
            e0 = energy
        best[start * M] = e0
        dq = deque()
        dq.append((start, 0, e0))
        d = 0
        while dq:
            for _ in range(len(dq)):
                pos, mask, e = dq.popleft()
                if e <= 0:
                    continue
                if best[pos * M + mask] > e:
                    continue
                ne_base = e - 1
                for np_ in adj[pos]:
                    ne = energy if isR[np_] else ne_base
                    nmask = mask | litbit[np_]
                    if nmask == full:
                        return d + 1
                    idx = np_ * M + nmask
                    if best[idx] < ne:
                        best[idx] = ne
                        dq.append((np_, nmask, ne))
            d += 1
        return -1