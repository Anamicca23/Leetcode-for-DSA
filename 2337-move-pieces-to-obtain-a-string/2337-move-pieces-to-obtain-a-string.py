class Solution:
    def canChange(self, s: str, t: str) -> bool:
        n=len(s)
        s+='@'
        t+='@'
        i, j=0, 0
        while i<n or j<n:
            while i<n and s[i]=='_': i+=1
            while j<n and t[j]=='_': j+=1
            c=s[i]
            if c!=t[j]: return False
            if c=='L' and i<j: return False
            if c=='R' and i>j: return False
            i+=1
            j+=1
        return True
        
        