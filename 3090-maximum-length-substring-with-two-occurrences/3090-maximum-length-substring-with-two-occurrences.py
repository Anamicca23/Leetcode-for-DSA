class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        res = l = 0
        fq = defaultdict(int)

        for r, ch in enumerate(s):
            fq[ch] += 1
            while fq[ch] > 2:
                fq[s[l]] -= 1
                l += 1
                
            res = max(res, r - l + 1)

        return res