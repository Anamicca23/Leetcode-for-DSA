class Solution:
    def punishmentNumber(self, n):
        # if n is punishment then add square to result
        return sum(i**2 for i in range(1, n + 1) if isPunishment(i * i, i))

@cache # avoid rechecking same (split, target) params
def isPunishment(split, target):
    if target < 0 or split < target:
        return False  # split always >= 0 and split only decreases in value
    if split == target:
        return True  # last split = target - previous splits, same as sum splits = target
        
    return ( # check if any split is valid
        isPunishment(split // 10, target - split % 10)          # split last digit      123 -> 12, t - 3
        or isPunishment(split // 100, target - split % 100)     # split last 2 digits   123 -> 1,  t - 23
        or isPunishment(split // 1000, target - split % 1000)   # split last 3 digits   123 -> 0,  t - 123
    )   # splits are max 3 digits since target is max 3 digits