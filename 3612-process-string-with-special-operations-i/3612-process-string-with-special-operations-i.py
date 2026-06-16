class Solution:
    def processStr(self, s: str) -> str:
        ans = []

        for ch in s:
            if 'a' <= ch <= 'z':
                ans.append(ch)
            elif ch == '*':
                if ans:
                    ans.pop()
            elif ch == '#':
                ans += ans
            else:
                ans.reverse()

        return "".join(ans)