class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        pos = [i for i, ch in enumerate(s) if ch == '1']
        if len(pos) < k:
            return ""
        ans = ""
        for i in range(len(pos) - k + 1):
            start = pos[i]
            end = pos[i + k - 1]
            cur = s[start:end + 1]
            if ans == "" or len(cur) < len(ans) or (len(cur) == len(ans) and cur < ans):
                ans = cur
        return ans