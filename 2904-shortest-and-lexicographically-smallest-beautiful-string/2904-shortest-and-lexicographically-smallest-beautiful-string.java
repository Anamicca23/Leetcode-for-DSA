class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        List<Integer> pos = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                pos.add(i);
            }
        }
        if (pos.size() < k)
            return "";
        String ans = "";
        for (int i = 0; i + k - 1 < pos.size(); i++) {
            int start = pos.get(i);
            int end = pos.get(i + k - 1);
            String cur = s.substring(start, end + 1);
            if (ans.isEmpty() ||
                cur.length() < ans.length() ||
                (cur.length() == ans.length() && cur.compareTo(ans) < 0)) {
                ans = cur;
            }
        }
        return ans;
    }
}