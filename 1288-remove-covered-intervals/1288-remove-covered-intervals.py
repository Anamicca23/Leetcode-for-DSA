class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort(key=lambda x: (x[0], -x[1]))

        ans = len(intervals)

        low = intervals[0][0]
        high = intervals[0][1]

        for i in range(1, len(intervals)):

            if intervals[i][0] == low or intervals[i][1] <= high:
                ans -= 1
            else:
                low = intervals[i][0]
                high = intervals[i][1]

        return ans