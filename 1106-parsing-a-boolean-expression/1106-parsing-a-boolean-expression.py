class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for c in expression:
            if c == ')':
                exp = []
                while stack[-1] != '(':
                    exp.append(stack.pop() == 't')
                stack.pop()  # Pop the '('
                op = stack.pop()  # Get the operator before '('
                res = exp.pop()
                if op == '&':
                    while exp: res &= exp.pop()
                elif op == '|':
                    while exp: res |= exp.pop()
                else:
                    res = not res
                stack.append('t' if res else 'f')
            elif c != ',':
                stack.append(c)
        return stack.pop() == 't'
