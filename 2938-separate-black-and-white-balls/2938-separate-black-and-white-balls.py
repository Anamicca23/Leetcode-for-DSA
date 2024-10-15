class Solution:
    def minimumSteps(self, s: str) -> int:
        swap, black = 0, 0
        for c in s:
            if c == "0":
                swap += black
            else:
                black += 1
        return swap