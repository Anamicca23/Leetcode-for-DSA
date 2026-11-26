class Solution:
    def canAliceWin(self, n: int) -> bool:
        return (0x61F03F807FC00 >> n & 1) == 1