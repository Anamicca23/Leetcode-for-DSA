class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        rev = 0
        while x != 0:
            last = x % 10
            rev = rev * 10 + last
            x = x // 10
    
        rev = sign * rev
        if rev > 2**31 - 1 or rev < -2**31:
            return 0
        
        return rev
