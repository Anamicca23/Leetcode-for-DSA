import java.util.Stack;

class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char c : expression.toCharArray()) {
            if (c == ')') {
                Stack<Boolean> exp = new Stack<>();
                while (stack.peek() != '(') exp.push(stack.pop() == 't');
                stack.pop();  // Pop the '('
                char op = stack.pop();  // Get the operator before '('
                boolean res = exp.pop();
                if (op == '&') while (!exp.isEmpty()) res &= exp.pop();
                else if (op == '|') while (!exp.isEmpty()) res |= exp.pop();
                else res = !res;
                stack.push(res ? 't' : 'f');
            } else if (c != ',') {
                stack.push(c);
            }
        }
        return stack.pop() == 't';
    }
}
