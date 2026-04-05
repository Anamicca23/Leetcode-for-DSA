class Solution:
    def judgeCircle(self, moves: str) -> bool:
        count_v = 0
        count_h = 0
        for ch in moves:
            if ch == 'U':
                count_v += 1
            elif ch == 'D':
                count_v -= 1
            elif ch == 'R':
                count_h += 1
            else:
                count_h -= 1

        return count_v == 0 and count_h == 0 