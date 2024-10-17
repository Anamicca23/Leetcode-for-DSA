class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        
        # Loop through each digit in the number
        for i in range(len(s)):
            # Try to find a larger digit that appears later in the string
            for d in range(9, int(s[i]), -1):
                j = ''.join(s).rfind(str(d))
                # If such a digit is found and it's after the current position
                if j > i:
                    # Swap the digits
                    s[i], s[j] = s[j], s[i]
                    # Return the result after converting the list back to integer
                    return int(''.join(s))
        
        return num  # If no swap is made, return the original number
