class Solution {
    public int numberOfSpecialChars(String word){
        HashSet<Character> set = new HashSet<>();
        for(char ch : word.toCharArray()) {
            set.add(ch);
        }
        int count = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(set.contains(ch) && set.contains((char)(ch - 'a' + 'A'))) {
                count++;
            }
        }
        return count;
    }
}