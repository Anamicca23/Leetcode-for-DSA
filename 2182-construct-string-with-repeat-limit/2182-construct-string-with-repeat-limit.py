class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        chars = Counter(s)
        sorted_chars = sorted(chars.items(), reverse=True)
        
        ans = []
        
        while sorted_chars:
            char, freq = sorted_chars[0]
            if freq <= repeatLimit:
                ans.append(char * freq)
                sorted_chars.pop(0)
            else:
                ans.append(char * repeatLimit)
                sorted_chars[0] = (char, freq - repeatLimit)
                
                if len(sorted_chars) > 1:
                    next_char, next_freq = sorted_chars[1]
                    ans.append(next_char)
                    if next_freq == 1:
                        sorted_chars.pop(1)
                    else:
                        sorted_chars[1] = (next_char, next_freq - 1)
                else:
                    break
        
        return ''.join(ans)