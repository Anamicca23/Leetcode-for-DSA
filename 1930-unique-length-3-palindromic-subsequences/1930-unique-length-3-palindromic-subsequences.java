import java.util.BitSet;

class Solution {
    public int countPalindromicSubsequence(String s) {
        BitSet exist = new BitSet(26);
        int ans = 0;
        
        for (int i = 0; i < 26; i++) {
            int l = s.indexOf('a' + i);
            if (l == -1) continue;
            int r = s.lastIndexOf('a' + i);
            if (r - l < 2) continue;
            
            for (int k = l + 1; k < r; k++) {
                exist.set(s.charAt(k) - 'a');
                if (exist.cardinality() == 26) break;
            }
            ans += exist.cardinality();
            exist.clear();
        }
        return ans;
    }
}
