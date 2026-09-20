class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0
        for i, ch in enumerate(s):
            temp = 26 - (ord(ch) - ord('a'))
            ans += temp * (i + 1)
        return ans