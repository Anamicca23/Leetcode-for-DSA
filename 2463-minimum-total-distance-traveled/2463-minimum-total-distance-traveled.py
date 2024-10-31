class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        n, m = len(robot), len(factory)
        dp = [1e13] * (n + 1)
        dp[0] = 0
        robot.sort()
        factory.sort()
        
        for position, limit in factory:
            for _ in range(limit):
                for j in range(n - 1, -1, -1):
                    dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j])
        
        return int(dp[n])
