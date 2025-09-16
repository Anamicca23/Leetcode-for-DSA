import java.util.*;

class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        LinkedList<Integer> stack = new LinkedList<>();

        for (int num : nums) {
            stack.add(num);

            while (stack.size() > 1) {
                int a = stack.getLast();
                int b = stack.get(stack.size() - 2);

                int g = gcd(a, b);
                if (g == 1) break;

                stack.removeLast();
                stack.removeLast();
                stack.add(lcm(a, b, g));
            }
        }
        return stack;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private int lcm(int a, int b, int g) {
        return (int)((long)a / g * b);  // prevent overflow
    }
}