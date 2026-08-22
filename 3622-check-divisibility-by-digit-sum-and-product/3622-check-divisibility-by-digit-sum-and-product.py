class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum_digit = 0
        product_digit = 1
        num = n
        while num > 0:
            sum_digit += num % 10
            product_digit *= num % 10
            num //= 10
        return n % (sum_digit + product_digit) == 0
