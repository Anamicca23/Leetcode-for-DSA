import math

class Solution:
    @staticmethod
    def maxCount(banned, n, maxSum):
        banned.append(n + 1)  # Add n+1 to simplify logic
        banned.sort()
        prev, remain, cnt = 0, maxSum, 0

        for x in banned:
            if x > n + 1:
                break
            if x == prev:
                continue
            d = x - prev - 1
            total_sum = (prev + x) * d // 2  # Arithmetic progression
            if total_sum <= remain:
                cnt += d
                remain -= total_sum
            else:
                # Use quadratic formula to find largest y such that sum <= remain
                y = int((-1 + math.sqrt(1 + 4 * ((prev + 1) * prev + 2 * remain))) // 2)
                cnt += y - prev
                break
            prev = x

        return cnt

