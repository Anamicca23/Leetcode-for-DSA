class Solution:
    def rotatedDigits(self, n: int) -> int:
        cnt = 0
        for num in range(1, n + 1):
            check = num
            valid = True
            changed = False
            while check > 0 and valid:
                digit = check  % 10
                if digit in (3, 4, 7):
                    valid = False
                elif digit in (2, 5, 6, 9):
                    changed = True
                check //= 10
            if valid and changed:
                cnt += 1
        return cnt