class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        if len(str2) > len(str1):
            return False
        test = 0
        for i in range(len(str1)):
            if test < len(str2):
                if str1[i] == str2[test]:
                    test += 1
                elif chr((ord(str1[i]) - ord('a') + 1) % 26 + ord('a')) == str2[test]:
                    test += 1
        return test == len(str2)
