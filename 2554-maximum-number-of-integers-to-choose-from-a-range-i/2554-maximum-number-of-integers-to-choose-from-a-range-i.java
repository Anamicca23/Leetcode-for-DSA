import java.util.*;

class Solution {
    public static int maxCount(List<Integer> banned, int n, int maxSum) {
        banned.add(n + 1); // Add n+1 to simplify logic
        Collections.sort(banned);
        int prev = 0, remain = maxSum, cnt = 0;

        for (int x : banned) {
            if (x > n + 1) break;
            if (x == prev) continue;
            int d = x - prev - 1;
            int sum = (prev + x) * d / 2; // Arithmetic progression
            if (sum <= remain) {
                cnt += d;
                remain -= sum;
            } else {
                // Use quadratic formula to find the largest y such that sum <= remain
                int y = (int)((-1 + Math.sqrt(1 + 4 * ((prev + 1) * prev + 2L * remain))) / 2.0);
                cnt += y - prev;
                break;
            }
            prev = x;
        }
        return cnt;
    }

    public static void main(String[] args) {
        List<Integer> banned = Arrays.asList(1, 4, 5);
        int n = 10, maxSum = 25;
        System.out.println(maxCount(banned, n, maxSum)); // Example usage
    }
}
