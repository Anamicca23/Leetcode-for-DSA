class Solution:
    def countTriples(self, n: int) -> int:
        
        # Helper function for GCD
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
            
        cnt = 0
        m = 2
        
        # Iterate m while smallest possible hypotenuse m^2 + 1 <= n
        while m * m < n:
            # Iterate k from 1 to m
            for k in range(1, m):
                # Check for primitive triple conditions:
                # 1. gcd(m, k) == 1 (coprime)
                # 2. One is even, one is odd -> (m - k) is odd
                if gcd(m, k) == 1 and (m - k) % 2 == 1:
                    c_primitive = m * m + k * k
                    
                    if c_primitive > n:
                        break
                    
                    # Add multiples of the primitive triple
                    # Multiply by 2 for both orderings (a,b) and (b,a)
                    cnt += 2 * (n // c_primitive)
            m += 1
            
        return cnt
