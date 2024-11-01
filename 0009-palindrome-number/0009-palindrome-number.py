class Solution:
    def isPalindrome(self, x: int) -> bool:
        # If x is negative, it cannot be a palindrome
        if x < 0:
            return False
        
        reversed_number = 0
        temp = x
        
        # Reverse the number
        while temp != 0:
            last_digit = temp % 10
            reversed_number = reversed_number * 10 + last_digit
            temp //= 10
        
        # Check if the reversed number matches the original
        return reversed_number == x
