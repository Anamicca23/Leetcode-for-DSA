class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def productOfDigits(num):
            product = 1
            while num:
                product *= num % 10
                num //= 10
            return product

        while productOfDigits(n) % t != 0:
            n += 1
        return n