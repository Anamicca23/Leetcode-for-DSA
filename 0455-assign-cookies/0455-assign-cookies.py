class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        n = len(s)
        g.sort(reverse=True) # Sort g in descending order
        s.sort(reverse=True) # Sort s in descending order
        curr, total = 0, 0
        for i in range(len(g)):
            if curr < n and g[i] <= s[curr]:
                curr += 1
                total += 1
        return total
