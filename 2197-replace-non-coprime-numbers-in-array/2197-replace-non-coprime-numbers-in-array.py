from math import gcd
from typing import List

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stack = []

        for num in nums:
            stack.append(num)

            # Merge while top two are non-coprime
            while len(stack) > 1:
                a = stack[-1]
                b = stack[-2]
                g = gcd(a, b)

                if g > 1:
                    l = (a // g) * b  # lcm
                    stack.pop()
                    stack.pop()
                    stack.append(l)
                else:
                    break
        return stack