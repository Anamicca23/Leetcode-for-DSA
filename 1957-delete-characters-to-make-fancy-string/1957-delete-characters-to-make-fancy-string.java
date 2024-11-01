class Solution {
    public String makeFancyString(String s) {
        if (s.length() < 3) return s;
        
        StringBuilder result = new StringBuilder(s.substring(0, 2));
        int j = 2;
        
        for (int i = 2; i < s.length(); ++i) {
            if (s.charAt(i) != result.charAt(j - 1) || s.charAt(i) != result.charAt(j - 2)) {
                result.append(s.charAt(i));
                j++;
            }
        }
        
        return result.toString();
    }
}
