class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        evenfreq1 = [0] * 26
        oddfreq1 = [0] * 26
        evenfreq2 = [0] * 26
        oddfreq2 = [0] * 26
        
        for i in range(len(s1)):
            char1idx = ord(s1[i]) - 97
            char2idx = ord(s2[i]) - 97
            if i % 2 == 0:
                evenfreq1[char1idx] += 1
                evenfreq2[char2idx] += 1
            else:
                oddfreq1[char1idx] += 1
                oddfreq2[char2idx] += 1
                
        return evenfreq1 == evenfreq2 and oddfreq1 == oddfreq2