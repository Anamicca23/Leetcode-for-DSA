class Solution {
    private static final int[][] modPow10 = new int[][]{
        {0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
        {1, 3, 2, 6, 4, 5, 1, 3, 2, 6, 4}, 
        {1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    }; //get mod pow 10 with modPow10[mod][exp]

    private static final int[] factorial = new int[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    public long countGoodIntegers(int n, int k) {
        /*
        for digits to even be able to rearrannge into a palindrome, need equal counnts of all digits, with possibly a single exception for center.
        Since good property needs to be able to rearrange into a palindrome, don't worry about order at first, just choose digits then find out how many 
        different n digit number perms said digit selection has if it can form a k-palindrome

        for even n:
            iterate through all sets of n/2 digits from 0-9. Since repeats are allowed, use r+s-1 choose s binom instead of r choose s
            This gives (10 + n/2 - 1) choose n/2. This caps at around 2000 with 14 choose 5, making set count relatively small
            
            once have a digit set, iterate through all perms of digits (without leading zeros) and see if there is one that when 
            do perm * (10^n/2) + reverse(perm) is divisible by k. (as this forms a pal)

            if we let the perm be represented by array perm where perm[0] is first (leading val) in perm and perm[n/2 - 1] is the last, 
            pal is also equiv to 

            perm[0] * 10^(n-1) + perm[1]*10^(n-2) + ... perm[n/2-1] * 10^(n/2) + perm[n/2-1]*10^(n/2 - 1) + ... perm[1]*10^1 + perm[0]
            = perm[0] * (10^(n-1) + 1) + perm[1] * (10^(n-2) + 10^1) + ... perm[i] * (10^(n-i-1) + 10^i) .... + perm[n/2-1] * (10^(n/2) + 10^(n/2-1))
            to be divisible by k, this needs to == 0 mod k, therefore a perm is a sol if it solves eq
            sum(perm[i] * (10^(n-i-1) + 10^i))[i = 0 to n/2 - 1] == 0 mod k under the condition that perm[0] != 0.

            for different k, have following for pows of 10
               k = 1:  10^s mod 1 == 0 for all s >= 0
                k > 1: all 10^0 mod k is trivially == 1 mod k

                k = 2, 5: 10^s mod k == 0 s >= 1
                k = 3, 9: 10^s mod k == 1 for all s >= 0
                k = 4: 10^s mod k == 2 for s == 1, 10^s mod k == 0 for s >= 2
                k = 6: 10^s mod k == 4 for s >= 1. 
                k = 8: 10^s mod k == 2 for s = 1, 10^2 mod k == 4, 10^s mod k for s >= 3 == 0. 
                k = 7: 10^s mod k. {s, k} pair set: {{1, 3}, {2, 2}, {3, 6}, {4, 4}, {5, 5}, {6, 1}, cycles from there for s congruence classes mod 7}
        
        Similar case for odd n, except now the palindrome is centered. 
            (Note for base case n = 1, can just return k/9 as this is 1 digit pos nums divis by k, and all are pals)

            So just have the same exact equation, but with added center (dont use center in perm, select center seperately)

            sum(perm[i] * (10^(n-i-1) + 10^i))[i = 0 to Floor(n/2) - 1]  + center == 0 mod k 
            center is some digit cDigit times 10^(floor(n/2))
            so have: sum(perm[i] * (10^(n-i-1) + 10^i))[i = 0 to Floor(n/2) - 1]  + cDigit*10^(floor(n/2)) == 0 mod k 
            or sum(perm[i] * (10^(n-i-1) + 10^i))[i = 0 to Floor(n/2) - 1]  == -cDigit*10^(floor(n/2)) mod k 

        */
        if(n == 1) return 9/k;
        return backtrackDigitCombos(0, 0, n, k,  new int[(n+1)/2]);
    }

    private long backtrackDigitCombos(int idx, int lo, int n, int k, int[] digits) {
        if(idx == digits.length) {
            if(digits[idx-1] == 0) return 0;
            if(n % 2 == 1) { //if odd need to pick a center.
                if(digits[idx-2] == 0) return hasKPalPerm(digits, n, k, 0, 1 << (idx-2), 0) ? validPermCnt(digits, n, 0) : 0;
                long res = 0;
                for(int c = 0; c < digits.length; c++) { 
                    if(c > 0 && digits[c] == digits[c-1]) continue;
                    if(hasKPalPerm(digits, n, k, (digits[c]*modPow10[k][n/2]) % k, 1 << c, 0)) {
                        res += validPermCnt(digits, n, digits[c]);
                    }
                }
                return res;
            }
            
            return hasKPalPerm(digits, n, k, 0, 0, 0) ? validPermCnt(digits, n, -1) : 0;
        }
        long res = 0;
        for(int d = lo; d <= 9; d++) {
            digits[idx] = d;
            res += backtrackDigitCombos(idx+1, d, n, k, digits);
        }
        return res;
    }

    private boolean hasKPalPerm(int[] digits, int n, int k, int residue, int mask, int chosenCnt) {
        if(chosenCnt == n/2) {
            return residue == 0;
        }

        for(int i = digits.length-1; i >= 0; i--) {
            if(chosenCnt == 0 && digits[i] == 0) break;
            if((mask & (1 << i)) != 0) continue;
            if(hasKPalPerm(digits, n, k, (residue + digits[i]*(modPow10[k][n-chosenCnt-1] + modPow10[k][chosenCnt])) % k, mask | (1 << i), chosenCnt+1)) return true;
        }

        return false;
    }

    private int validPermCnt(int[] digits, int n, int center) {
        /*want to get totalPerms - startZeroPerms to get perms non startign with zero
        total perms = n!/(product of factorial of repeat counts for elements to denote repeat subperms) = n!/((zeroCnt)!*(prod(cnt!) for all repeat cnts cnt)
        zeroStart perms (trivial case of zero when zeroCnt = 0), select one of the zeros to start the perm then permute the rest of the elements (now with zeroCnt-1 0's)
        zeroStart perms = (n-1)!/((zeroCnt-1)! * (prod(cnt!)))
        let total perms = tp, zero start perms = zp, prod of cnt!'s = p
        tp = n!/(zeroCnt! * p), zp = (n-1)!/((zeroCnt-1)! * p). 
        zp = (zeroCnt/n) * (n!/(zeroCnt! * p)) = (zeroCnt/n) * tp. 
            (note: involves mult by n/zeroCnt also so zeroCnt must be > 0, but even if zeroCnt = 0 reduced formula still works as (n-zeroCnt)*tp/n = n*tp/n = tp = tp-zp = tp-0)
        thus since want tp-zp, tp-zp = tp - (zeroCnt/n) * tp. = (1 - zeroCnt/n)*tp = ((n-zeroCnt)*tp)/n*/

        int nonZeroInd = 0;
        while(digits[nonZeroInd] == 0) nonZeroInd++;
        int zeroCnt = nonZeroInd * 2 - (center == 0 ? 1 : 0); //2x all counts as actual perm has it reflected in both sides of pal.

        long perms = factorial[n]/factorial[zeroCnt];
        int streak = 1;
        for(int i = nonZeroInd+1; i < digits.length; i++) { //perms of s diff elements = s!/(product of factorials of repeat elements to denote repeat subperms)
            if(digits[i] == digits[i-1]) {
                streak++;
            } else {
                perms /= factorial[2*streak - (digits[i-1] == center ? 1 : 0)];
                streak = 1;
            }
        }
        perms /= factorial[2*streak - (digits[digits.length-1] == center ? 1 : 0)];

        return (int)(perms*(n-zeroCnt)/n); //use tp-zp = ((n-zeroCnt)*tp)/n. (Note perms max = 10! < int lim and since perms*(n-zeroCnt)/n <= perms, fits in int)
    }

    
}