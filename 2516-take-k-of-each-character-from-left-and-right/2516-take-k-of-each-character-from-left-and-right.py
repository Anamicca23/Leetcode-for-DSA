class Solution:
    def takeCharacters(self,s,k):
        d={c:s.count(c)-k for c in'abc'}
        if min(d.values())<0:return-1
        h,m,l={c:0 for c in'abc'},0,0
        for r,c in enumerate(s):
            h[c]+=1
            while h[c]>d[c]:h[s[l]]-=1;l+=1
            m=max(m,r-l+1)
        return len(s)-m