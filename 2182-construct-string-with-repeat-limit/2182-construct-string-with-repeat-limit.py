class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        chars = sorted(s, reverse=True)
        
        result = []
        freq = 1
        pointer = 0
        
        for i in range(len(chars)):
            if result and result[-1] == chars[i]:
                if freq < repeatLimit:
                    result.append(chars[i])
                    freq += 1
                else:
                    pointer = max(pointer, i + 1)
                    while pointer < len(chars) and chars[pointer] == chars[i]:
                        pointer += 1
                    
                    if pointer < len(chars):
                        result.append(chars[pointer])
                        chars[i], chars[pointer] = chars[pointer], chars[i]
                        freq = 1
                    else:
                        break
            else:
                result.append(chars[i])
                freq = 1
        
        return ''.join(result)