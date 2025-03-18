class Solution:
    def merge(self, inr: List[List[int]]) -> List[List[int]]:
        inr.sort()
        ans = [inr[0]]
        for it in inr:
            if ans[-1][1] < it[0]: ans.append(it)
            else: ans[-1][1] = max(ans[-1][1], it[1])
        return ans
