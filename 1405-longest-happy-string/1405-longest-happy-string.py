import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = []  # Resultant string as list of characters
        max_heap = []
        
        # Push available characters with their frequencies
        if a > 0:
            heapq.heappush(max_heap, (-a, 'a'))
        if b > 0:
            heapq.heappush(max_heap, (-b, 'b'))
        if c > 0:
            heapq.heappush(max_heap, (-c, 'c'))
        
        while max_heap:
            cnt_curr, ch_curr = heapq.heappop(max_heap)  # Pop the character with max frequency
            cnt_curr = -cnt_curr  # Convert back to positive for use
            
            if len(res) < 2 or res[-1] != ch_curr or res[-2] != ch_curr:
                res.append(ch_curr)  # Append the character to the result
                cnt_curr -= 1  # Decrease frequency
                if cnt_curr > 0:
                    heapq.heappush(max_heap, (-cnt_curr, ch_curr))  # Reinsert if still has occurrences
            else:
                if not max_heap:
                    break  # No other characters available

                cnt_next, ch_next = heapq.heappop(max_heap)  # Next character with max frequency
                cnt_next = -cnt_next  # Convert to positive
                
                res.append(ch_next)  # Append the next character
                cnt_next -= 1  # Decrease frequency
                if cnt_next > 0:
                    heapq.heappush(max_heap, (-cnt_next, ch_next))  # Reinsert next character
                
                heapq.heappush(max_heap, (-cnt_curr, ch_curr))  # Reinsert the original character

        return ''.join(res)
