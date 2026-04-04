class Solution {
    public String decodeCiphertext(String s, int rows) {
        int n = s.length(), cols = n / rows;
        StringBuilder res = new StringBuilder(10);
        for (int i = 0; i < cols; ++i)
            for (int j = i; j < n; j += cols + 1)
                res.append(s.charAt(j));
        while (res.length()  > 0 && res.charAt(res.length() - 1) == ' ')
            res.setLength(res.length() - 1);
        return res.toString();
    }
}