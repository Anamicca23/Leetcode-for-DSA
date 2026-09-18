class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        counts = Counter(s)
        first = {c: s.find(c) for c in counts}
        last = {c: s.rfind(c) for c in counts}

        res = []
        queue = deque()

        for c in counts:
            queue.appendleft([first[c], last[c], counts[c]])

            left = inf
            right = -inf
            total = 0

            for x, y, z in queue:
                total += z
                left = min(left, x)
                right = max(right, y)

                if total == right - left + 1:
                    break

            if total == right - left + 1:
                res.append(s[left:right + 1])
                queue.clear()

        return res