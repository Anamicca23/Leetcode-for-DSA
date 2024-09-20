import java.util.ArrayList;
import java.util.List;

class Solution {
    
    // Z-function implementation
    public List<Integer> z_function(String s) {
        int n = s.length();
        List<Integer> z = new ArrayList<>(n);
        
        // Initialize the list with zeros
        for (int i = 0; i < n; i++) {
            z.add(0);
        }

        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z.set(i, Math.min(z.get(i - l), r - i));
            }
            while (i + z.get(i) < n && s.charAt(i + z.get(i)) == s.charAt(z.get(i))) {
                z.set(i, z.get(i) + 1);
            }
            if (i + z.get(i) > r) {
                l = i;
                r = i + z.get(i);
            }
        }
        return z;
    }

    // Function to return the shortest palindrome
    public String shortestPalindrome(String s) {
        int n = s.length();
        
        // Create reversed version of the string
        StringBuilder t = new StringBuilder(s);
        t.reverse();
        
        // Combine original and reversed strings with a separator
        String combined = s + "#" + t.toString();
        
        // Get Z-function values for the combined string
        List<Integer> z = z_function(combined);
        
        int maxPalindromeLength = 0;
        for (int i = 0; i < n; i++) {
            if (z.get(2 * n - i) == i + 1) {
                maxPalindromeLength = i + 1;
            }
        }
        
        // Form the result by appending the reversed remaining suffix
        String suffix = s.substring(maxPalindromeLength);
        StringBuilder ans = new StringBuilder(suffix);
        ans.reverse();
        
        return ans.toString() + s;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "aacecaaa";
        System.out.println(sol.shortestPalindrome(s));
    }
}
