class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        xr = 0
        for x in derived:
            xr ^= x
        return xr == 0