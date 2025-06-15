class Solution {
    private int difference(int num) {
        int firstNonNine = -1, firstNonOne = -1, firstDigit = -1;
        int remaining = num;
        while (remaining > 0) {
            int digit = remaining % 10;
            if (digit != 9) {
                firstNonNine = digit;
            }
            if (digit > 1) {
                firstNonOne = digit;
            }
            firstDigit = digit;
            remaining /= 10;
        }
        
        remaining = num;
        int min = 0, max = 0;
        int multiplier = 1;
        while (remaining > 0) {
            int digit = remaining % 10;
            
            int minDigit = digit;
            int maxDigit = digit;
            
            if (firstDigit == 1 && digit == firstNonOne) {
                minDigit = 0;
            }
            
            if (firstDigit != 1 && digit == firstDigit) {
                minDigit = 1;
            }

            if (digit == firstNonNine) {
                maxDigit = 9;
            }

            min += multiplier * minDigit;
            max += multiplier * maxDigit;

            multiplier *= 10;    
            remaining /= 10;
        }
        
        return max - min;
    }

    public int maxDiff(int num) {
        return difference(num);
    }
}