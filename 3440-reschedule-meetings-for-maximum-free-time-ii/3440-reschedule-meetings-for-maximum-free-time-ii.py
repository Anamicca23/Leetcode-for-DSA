class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)

        # Step 1: Combine start and end times into intervals
        intervals = sorted(zip(startTime, endTime))

        # Step 2: Sort intervals by start time (already done in one line above)

        # Step 3: Calculate free time gaps
        gaps = [intervals[0][0]]  # before the first meeting
        for i in range(1, n):
            gaps.append(intervals[i][0] - intervals[i - 1][1])  # between meetings
        gaps.append(eventTime - intervals[-1][1])  # after the last meeting

        # Step 4: Precompute max gaps before and after each meeting
        maxBefore = [0] * (n + 2)
        maxAfter = [0] * (n + 2)
        for i in range(1, n + 1):
            maxBefore[i] = max(maxBefore[i - 1], gaps[i - 1])
        for i in range(n, 0, -1):
            maxAfter[i] = max(maxAfter[i + 1], gaps[i])

        maxFree = 0

        # Step 5: Try removing each meeting and calculate impact
        for i in range(n):
            duration = intervals[i][1] - intervals[i][0]
            leftGap = gaps[i]
            rightGap = gaps[i + 1]
            combinedGap = leftGap + rightGap

            bestGap = max(maxBefore[i] if i > 0 else 0,
                          maxAfter[i + 2] if i < n - 1 else 0)

            if duration <= bestGap:
                maxFree = max(maxFree, combinedGap + duration)
            else:
                maxFree = max(maxFree, combinedGap)

        # Step 6: Consider largest original gap without rescheduling
        for gap in gaps:
            maxFree = max(maxFree, gap)

        # Step 7: Return the result
        return maxFree