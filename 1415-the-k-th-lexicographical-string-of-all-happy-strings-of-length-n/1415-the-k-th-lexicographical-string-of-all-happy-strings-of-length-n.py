class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        sz = 2 ** (n - 1)
        if 3 * sz < k:
            return ""
        opts = ["bc", "ac", "ab"]
        if k <= sz:         res = "a"
        elif k <= 2 * sz:   res = "b"; k -= sz
        else:               res = "c"; k -= 2 * sz
        for i in range(1, n):
            sz //= 2
            ch = opts[ord(res[-1]) - ord('a')]
            if k <= sz: res += ch[0]
            else:       res += ch[1]; k -= sz
        return res