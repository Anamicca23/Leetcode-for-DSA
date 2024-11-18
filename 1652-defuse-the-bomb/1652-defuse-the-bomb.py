class Solution:
    def decrypt(self, circ: List[int], k: int) -> List[int]:
        n = len(circ)  # circular array
        result = [0] * n
        
        if k == 0:
            return result
            
        start = 1 if k > 0 else n + k
        end = k if k > 0 else n - 1
        
        wSum = sum(circ[i % n] for i in range(start, end + 1))
        
        for i in range(n):
            result[i] = wSum
            wSum -= circ[(start + i) % n]
            wSum += circ[(end + i + 1) % n]
            
        return result