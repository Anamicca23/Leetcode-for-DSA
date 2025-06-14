class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = str(num)

        # Max transformation
        replace_for_max = ''
        for c in s:
            if c != '9':
                replace_for_max = c
                break
        max_str = ''.join(['9' if c == replace_for_max else c for c in s])

        # Min transformation
        replace_for_min = s[0]
        min_str = ''.join(['0' if c == replace_for_min else c for c in s])

        return int(max_str) - int(min_str)