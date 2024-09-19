class Solution:
    def solve(self, s: str) -> list[int]:
        res = []
        
        for i in range(len(s)):
            c = s[i]
            
            if c in "+-*":
                left = self.solve(s[:i])
                right = self.solve(s[i+1:])
                
                for l in left:
                    for r in right:
                        if c == '+':
                            res.append(l + r)
                        elif c == '-':
                            res.append(l - r)
                        else:  # c == '*'
                            res.append(l * r)
        

        if not res:
            res.append(int(s))
        
        return res

    def diffWaysToCompute(self, expression: str) -> list[int]:
        return self.solve(expression) 