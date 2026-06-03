class Solution:
    def calFinishTime(self, ls, ld, ws, wd):

        mini = float('inf')

        for i in range(len(ls)):
            mini = min(mini, ls[i] + ld[i])

        ans = float('inf')

        for i in range(len(ws)):
            ans = min(
                ans,
                max(mini, ws[i]) + wd[i]
            )

        return ans

    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        return min(
            self.calFinishTime(landStartTime,landDuration,waterStartTime,waterDuration),
            self.calFinishTime(waterStartTime,waterDuration,landStartTime,landDuration)
        )