class Solution:
    def numSpecial(self, mat):
        m = len(mat)
        n = len(mat[0])

        rowcnt = [0] * m
        colcnt = [0] * n

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    rowcnt[i] += 1
                    colcnt[j] += 1

        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and rowcnt[i] == 1 and colcnt[j] == 1:
                    ans += 1

        return ans