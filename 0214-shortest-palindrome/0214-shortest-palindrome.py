class Solution:
    
    # Z-function implementation
    def z_function(self, s: str) -> list[int]:
        n = len(s)
        z = [0] * n
        l, r = 0, 0
        for i in range(1, n):
            if i < r:
                z[i] = min(z[i - l], r - i)
            while i + z[i] < n and s[i + z[i]] == s[z[i]]:
                z[i] += 1
            if i + z[i] > r:
                l, r = i, i + z[i]
        return z

    # Function to return the shortest palindrome
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        
        # Create reversed version of the string
        t = s[::-1]
        
        # Combine original and reversed strings with a separator
        combined = s + '#' + t
        
        # Get Z-function values for the combined string
        z = self.z_function(combined)
        
        max_palindrome_length = 0
        for i in range(n):
            if z[2 * n - i] == i + 1:
                max_palindrome_length = i + 1
        
        # Form the result by appending the reversed remaining suffix
        suffix = s[max_palindrome_length:]
        return suffix[::-1] + s

