class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)

        # Create DP table
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1  # If characters match
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])  # Take max from either previous row or column

        # Build the shortest common supersequence
        result = []
        i, j = m, n
        while i > 0 and j > 0:
            # If characters are the same, add to the result
            if str1[i - 1] == str2[j - 1]:
                result.append(str1[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] > dp[i][j - 1]:  # Move in the direction of larger dp value
                result.append(str1[i - 1])
                i -= 1
            else:
                result.append(str2[j - 1])
                j -= 1

        # If there are any remaining characters in str1
        while i > 0:
            result.append(str1[i - 1])
            i -= 1

        # If there are any remaining characters in str2
        while j > 0:
            result.append(str2[j - 1])
            j -= 1

        # Reverse the result before returning
        return ''.join(result[::-1])