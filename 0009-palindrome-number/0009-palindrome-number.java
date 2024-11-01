class Solution {
    public boolean isPalindrome(int x) {
        // If x is negative, it cannot be a palindrome
        if (x < 0) return false;
        
        long reversedNumber = 0;
        int temp = x;
        
        // Reverse the number
        while (temp != 0) {
            int lastDigit = temp % 10;
            reversedNumber = reversedNumber * 10 + lastDigit;
            temp /= 10;
        }
        
        // Check if the reversed number matches the original
        return (reversedNumber == x);
    }
}
