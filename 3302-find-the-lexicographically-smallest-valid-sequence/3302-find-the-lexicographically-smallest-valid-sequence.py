class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n = len(word2)
        last = [-1]*n
        j = n-1
        for i, ch in reversed(list(enumerate(word1))): 
            if j >= 0 and ch == word2[j]: 
                last[j] = i 
                j -= 1
        j = cnt = 0 
        ans = []
        for i, ch in enumerate(word1): 
            if j < n: 
                if ch == word2[j] or cnt == 0 and (j == n-1 or i+1 <= last[j+1]): 
                    if ch != word2[j]: cnt = 1
                    ans.append(i)
                    j += 1
        return ans if j == n else []