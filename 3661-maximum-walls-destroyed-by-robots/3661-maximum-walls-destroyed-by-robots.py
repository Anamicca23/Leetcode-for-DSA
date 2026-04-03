class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        A = sorted(zip(robots, distance))
        N = len(A)
        walls.sort()

        def count(L, R):
            if L > R:
                return 0
            return bisect_right(walls, R) - bisect_left(walls, L)

        avail = 0
        used = count(A[0][0] - A[0][1], A[0][0] - 1)
        A.append([inf, 0])
        for i in range(N):
            l, dl = A[i]
            r, dr = A[i + 1]

            l1, r1 = l + 1, min(l + dl, r - 1)
            l2, r2 = max(r - dr, l + 1), r - 1
            
            left = count(l1, r1)
            right = count(l2, r2)
            both = left + right - count(max(l1, l2), min(r1, r2))

            navail = max(avail + left, used)
            nused = max(avail + both, used + right)
            avail, used = navail, nused

        for x in set(x for x,_ in A):
            used += count(x, x)
        return used