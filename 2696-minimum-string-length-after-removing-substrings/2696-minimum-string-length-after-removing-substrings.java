import java.util.Stack;

public class Solution {
    public int minLength(String s) {
        Stack<Character> stack = new Stack<>();
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char currentChar = s.charAt(i);
            if (!stack.isEmpty() && 
               ((stack.peek() == 'A' && currentChar == 'B') ||
                (stack.peek() == 'C' && currentChar == 'D'))) {
                stack.pop();
            } else {
                stack.push(currentChar);
            }
        }
        
        return stack.size();
    }
}
