class Solution {
    int hamming(String s1, String s2) {
        int h = 0;
        for (int i = 0; i < s1.length(); ++i) {
            h += s1.charAt(i) != s2.charAt(i) ? 1 : 0;
        }
        return h;
    };

    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        ArrayList<String> words = new ArrayList<>();
        for (String q : queries)
            for (String d : dictionary)
                if (hamming(q, d) <= 2) {
                    words.add(q);
                    break;
                }
        return words;
    }
}