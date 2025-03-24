class Solution:
    def merge(self, A):
        A.sort()
        res = [A[0]]
        for i in range(1, len(A)):
            if res[-1][1] >= A[i][0]:
                res[-1][1] = max(res[-1][1], A[i][1])
            else:
                res.append(A[i])
        return res

    def countDays(self, days, A):
        newA = self.merge(A)
        for interval in newA:
            days -= (interval[1] - interval[0] + 1)
        return days