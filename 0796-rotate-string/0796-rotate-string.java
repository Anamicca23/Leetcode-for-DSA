class Solution {
    public boolean rotateString(String s, String goal) {
        int n = s.length(), m = goal.length();
        if (m != n) return false;
        return (s + s).contains(goal);
    }
}
