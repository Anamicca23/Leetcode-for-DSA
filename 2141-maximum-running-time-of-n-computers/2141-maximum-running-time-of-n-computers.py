class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        totalEnergy = sum(batteries)
        batteries.sort()

        for i in range(len(batteries) - 1, -1, -1):
            if batteries[i] > totalEnergy // n:
                totalEnergy -= batteries[i]
                n -= 1
            else:
                break

        return totalEnergy // n