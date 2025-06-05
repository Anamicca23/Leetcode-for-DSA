class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def find(char):
            i = ord(char) - ord("a")
            while root[i] != i:
                i = root[i]
            return i
        
        root = list(range(26))
        for char1, char2 in zip(s1,s2):
            r1 = find(char1)
            r2 = find(char2)
            if r1 > r2:
                r1, r2 = r2, r1
            
            root[r2] = r1
        
        return "".join(chr(ord("a") + find(char)) for char in baseStr)