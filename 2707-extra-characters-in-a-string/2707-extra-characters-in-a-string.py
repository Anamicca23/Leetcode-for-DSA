class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dp = [0] * (n + 1) 
        for i in range(1, n + 1):
            dp[i] = dp[i - 1] + 1 
            for word in dictionary:
                m = len(word)
                if i >= m and s[i - m:i] == word:
                    dp[i] = min(dp[i], dp[i - m])  

        return dp[n]  
 