class Solution:
    def maximum69Number (self, num: int) -> int:
        for i in [1000, 100, 10, 1]:
            if (num // i) % 10 == 6:
                num += 3 * i
                break
        return num