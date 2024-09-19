import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> solve(String s) {
        List<Integer> res = new ArrayList<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '+' || c == '-' || c == '*') {
                List<Integer> left = solve(s.substring(0, i));
                List<Integer> right = solve(s.substring(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            res.add(l + r);
                        } else if (c == '-') {
                            res.add(l - r);
                        } else {
                            res.add(l * r);
                        }
                    }
                }
            }
        }
        if (res.isEmpty()) {
            res.add(Integer.parseInt(s));
        }
        
        return res;
    }
    
    public List<Integer> diffWaysToCompute(String expression) {
        return solve(expression);
    }
}
