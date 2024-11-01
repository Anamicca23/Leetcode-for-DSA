class Solution:
    def reverse(self, x: int) -> int:
        num = int(("-" if x < 0 else "") + (str(x if x > 0 else -x)[::-1]))
        return 0 if num > 2 ** 31 or num < -(2**31) else num
        