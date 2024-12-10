from collections import defaultdict

class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        mapie = defaultdict(int)

        # Populate the map with character-length frequency
        for i in range(n):
            l = 0
            for j in range(i, n):
                if s[j] == s[i]:
                    l += 1
                    mapie[(s[i], l)] += 1
                else:
                    break

        # Find the maximum length
        res = 0
        for (char, length), freq in mapie.items():
            if freq >= 3 and length > res:
                res = length

        return -1 if res == 0 else res
