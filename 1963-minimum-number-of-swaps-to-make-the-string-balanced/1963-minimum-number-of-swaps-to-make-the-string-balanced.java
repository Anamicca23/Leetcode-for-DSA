public class Solution {
    public int minSwaps(String s) {
        int i = 0, j = s.length() - 1;
        int cur = 0, swaps = 0;

        char[] chars = s.toCharArray();
        
        while (i < j) {
            if (chars[i] == '[') {
                ++cur;
            } else {
                --cur;
            }
            
            if (cur < 0) {
                while (chars[j] != '[') {
                    --j;
                }
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;

                ++swaps;
                cur = 1;
            }
            ++i;
        }
        
        return swaps;
    }
}
