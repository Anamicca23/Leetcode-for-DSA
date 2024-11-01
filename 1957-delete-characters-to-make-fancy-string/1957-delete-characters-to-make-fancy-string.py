class Solution:
    def makeFancyString(self, s: str) -> str:
        ret = []
        cnt = 1
        prev = None
        for c in s:
            if c == prev:
                cnt += 1
            else:
                cnt = 1
            prev = c
            if cnt < 3:
                ret.append(c)
        return ''.join(ret)
        