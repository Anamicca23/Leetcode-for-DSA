class Solution:
    def minLength(self, s: str) -> int:
        s1=[]
        for p in s:
            if(s1 and((s1[-1]=="A" and p=="B") or(s1[-1]=="C" and p=="D"))):
                s1.pop()
            else:
                s1.append(p)
        return (len(s1))