class Solution(object):
    def minimumDeletions(self, word, k):
        freq = [0] * 26
        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        freq_list = [f for f in freq if f > 0]
        freq_list.sort()

        n = len(freq_list)
        total = len(word)
        removed_left = 0
        window_sum = 0
        result = total  
        r = 0

        for l in range(n):
            base = freq_list[l]
            limit = base + k

            while r < n and freq_list[r] <= limit:
                window_sum += freq_list[r]
                r += 1
            
            right_count = n - r
            right_sum = total - window_sum
            del_right = right_sum - right_count * limit

            curr = removed_left + del_right
            if curr < result:
                result = curr

            total -= base
            removed_left += base
            window_sum -= base

        return result