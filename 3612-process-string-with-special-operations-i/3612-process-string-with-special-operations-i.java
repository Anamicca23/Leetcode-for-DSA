class Solution {
    public String processStr(String s) {
        StringBuilder ans = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                ans.append(ch);
            }
            else if (ch == '*') {
                if (ans.length() > 0) {
                    ans.deleteCharAt(ans.length() - 1);
                }
            }
            else if (ch == '#') {
                ans.append(ans.toString());
            }
            else {
                ans.reverse();
            }
        }
        return ans.toString();
    }
}