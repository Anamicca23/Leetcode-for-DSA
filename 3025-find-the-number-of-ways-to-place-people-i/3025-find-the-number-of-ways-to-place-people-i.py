class Solution:
    def numberOfPairs(self, points: list[list[int]]) -> int:
        n = len(points)
        count = 0

        for i in range(n):
            x1, y1 = points[i]
            for j in range(n):
                if i == j:
                    continue
                x2, y2 = points[j]
                
                if x1 > x2 or y1 < y2:
                    continue

                flag = True
                for k in range(n):
                    if k == i or k == j:
                        continue
                    x, y = points[k]
                    if x >= x1 and x <= x2 and y <= y1 and y >= y2:
                        flag = False
                        break

                if flag:
                    count += 1

        return count