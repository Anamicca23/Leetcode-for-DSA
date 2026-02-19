class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n=len(s)
        prev, cur, cnt=0, 1, 0
        for c0, c1 in pairwise(s):
            if c0==c1:
                cur+=1
            else:
                cnt+=min(cur, prev)
                prev=cur
                cur=1
        return cnt+min(cur, prev)
        