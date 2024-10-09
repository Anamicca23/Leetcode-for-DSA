public class Solution {
    public int minAddToMakeValid(String s) {
        int size = 0;
        int openb = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                size++;
            } else {
                if (size > 0) {
                    size--;
                } else {
                    openb++;
                }
            }
        }

        return openb + size;
    }
}
