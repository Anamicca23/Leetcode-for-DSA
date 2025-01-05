class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n, sz= len(s), len(shifts)
        app=[0]*(n+1)
        for b, e, d in shifts:
            app[b]+=(d*2-1)
            app[e+1]-=(d*2-1)
        app=list(accumulate(app))
        s0=[]
        for i, c in enumerate(s):
            t=(app[i]+ord(c)-97)%26+97
            if t<97: t+=26
            s0.append(chr(t))
        return "".join(s0)