from functools import lru_cache

class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        n = len(days)
        dp = [-1] * n

        def calculate_min_cost(i: int) -> int:
            if i >= n:
                return 0
            if dp[i] != -1:
                return dp[i]

            ans, j = float("inf"), i
            for d, cost in zip([1, 7, 30], costs):
                while j < n and days[j] < days[i] + d:
                    j += 1
                ans = min(ans, calculate_min_cost(j) + cost)

            dp[i] = ans
            return ans

        return calculate_min_cost(0)
