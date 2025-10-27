class Solution {
    public int numberOfBeams(String[] bank) {
        int prev = 0;
        int ans = 0;

        for (String row : bank) {
            int cur = 0;
            for (char c : row.toCharArray()) {
                if (c == '1') cur++;
            }

            if (cur > 0) {
                ans += prev * cur;
                prev = cur;
            }
        }
        return ans;
    }
}