import java.util.*;

class Solution {
    static final int MOD = 1_000_000_007;
    
    // Matrix multiplication
    private long[][] multiply(long[][] a, long[][] b) {
        long[][] res = new long[26][26];
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    
    // Matrix exponentiation
    private long[][] matrixPow(long[][] mat, int power) {
        long[][] result = new long[26][26];
        for (int i = 0; i < 26; ++i) {
            result[i][i] = 1;
        }
        while (power > 0) {
            if (power % 2 == 1) {
                result = multiply(result, mat);
            }
            mat = multiply(mat, mat);
            power /= 2;
        }
        return result;
    }
    
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        // Initialize the transition matrix
        long[][] transition = new long[26][26];
        for (int c = 0; c < 26; ++c) {
            int num = nums.get(c);
            for (int j = 1; j <= num; ++j) {
                int nextChar = (c + j) % 26;
                transition[c][nextChar]++;
            }
        }
        
        // Raise the transition matrix to the t-th power
        long[][] matPow = matrixPow(transition, t);
        
        // Initialize the initial count vector
        long[] cnt = new long[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        
        // Multiply the count vector by the matrix^t
        long[] newCnt = new long[26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                newCnt[j] = (newCnt[j] + cnt[i] * matPow[i][j]) % MOD;
            }
        }
        
        // Sum all the counts
        long total = 0;
        for (long x : newCnt) {
            total = (total + x) % MOD;
        }
        return (int)total;
    }
}