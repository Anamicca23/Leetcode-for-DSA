class Solution(object):
    def removeOccurrences(self, s, part):
        while part in s:
            s = s.replace(part, "", 1)  # Remove only the first occurrence
        return s