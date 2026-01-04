from typing import List
import math

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total = 0
        for x in nums:
            cnt = 0
            s = 0
            i = 1
            while i * i <= x:
                if x % i == 0:
                    j = x // i
                    cnt += 1
                    s += i
                    if i != j:
                        cnt += 1
                        s += j
                    if cnt > 4:
                        break
                i += 1
            if cnt == 4:
                total += s
        return total