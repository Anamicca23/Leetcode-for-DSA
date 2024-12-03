class Solution:
    def addSpaces(self, s: str, spaces: list[int]) -> str:
        n = len(s)
        m = len(spaces)
        res = []
        j = 0

        for i in range(n):
            if j < m and i == spaces[j]:
                res.append(" ")
                j += 1
            res.append(s[i])

        return ''.join(res)
