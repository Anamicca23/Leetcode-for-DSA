import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    public String firstPalindrome(String[] words) {
        List<String> wordList = new ArrayList<>();
        for (String word : words) {
            wordList.add(word);
        }
        
        for (String word : wordList) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
}
