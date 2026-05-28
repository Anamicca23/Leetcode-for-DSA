class Solution {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int bestLen = Integer.MAX_VALUE;
        int bestIdx = Integer.MAX_VALUE;
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        TrieNode root = new TrieNode();
        
        for (int i = 0; i < wordsContainer.length; i++) {
            String word = wordsContainer[i];
            int len = word.length();
            TrieNode curr = root;
            
            if (len < curr.bestLen || (len == curr.bestLen && i < curr.bestIdx)) {
                curr.bestLen = len;
                curr.bestIdx = i;
            }
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = word.charAt(j) - 'a';
                
                if (curr.children[charIdx] == null) {
                    curr.children[charIdx] = new TrieNode();
                }
                
                curr = curr.children[charIdx];
                
                if (len < curr.bestLen || (len == curr.bestLen && i < curr.bestIdx)) {
                    curr.bestLen = len;
                    curr.bestIdx = i;
                }
            }
        }
        
        int[] ans = new int[wordsQuery.length];
        
        for (int i = 0; i < wordsQuery.length; i++) {
            String query = wordsQuery[i];
            int len = query.length();
            TrieNode curr = root;
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = query.charAt(j) - 'a';
                if (curr.children[charIdx] == null) {
                    break;
                }
                curr = curr.children[charIdx];
            }
            ans[i] = curr.bestIdx;
        }
        
        return ans;
    }
} 