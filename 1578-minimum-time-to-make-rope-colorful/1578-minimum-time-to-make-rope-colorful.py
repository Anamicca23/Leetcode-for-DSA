class Solution(object):
    def minCost(self, colors, neededTime):
        n, sum_ = len(colors), 0
        i = 1
        while i < n:
            maxi = 0
            while i < n and colors[i] == colors[i - 1]:
                sum_ += neededTime[i - 1]
                maxi = max(maxi, neededTime[i - 1])
                i += 1
            sum_ += neededTime[i - 1]
            maxi = max(maxi, neededTime[i - 1])
            if maxi != 0:
                sum_ -= maxi
            i += 1
        return sum_