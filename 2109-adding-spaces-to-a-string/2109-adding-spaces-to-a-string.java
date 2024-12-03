import java.util.*;

class Solution {
    public String addSpaces(String s, int[] spaces) {
        int n = s.length();
        int m = spaces.length;
        StringBuilder res = new StringBuilder();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                res.append(" ");
                j++;
            }
            res.append(s.charAt(i));
        }

        return res.toString();
    }
}
