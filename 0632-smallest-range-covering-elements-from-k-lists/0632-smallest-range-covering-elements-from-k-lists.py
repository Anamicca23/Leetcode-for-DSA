class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        d = defaultdict(list)
        for i, evs in enumerate(nums):
            for v in evs:
                d[v].append(i)
        keys = sorted(d.keys())
        lo = 0
        n = len(nums)
        dd = defaultdict(int)
        le, ri = -1, float('Inf')
        have = 0
        for hi in range(len(keys)):
            for x in d[keys[hi]]:
                dd[x] += 1
                if dd[x] == 1:
                    have += 1
            while have == n:
                curr = keys[hi] - keys[lo]
                if ri - le > curr:
                    ri = keys[hi]
                    le = keys[lo]
                for x in d[keys[lo]]:
                    dd[x] -= 1
                    if dd[x] == 0:
                        have -= 1
                lo += 1
        return [le, ri]