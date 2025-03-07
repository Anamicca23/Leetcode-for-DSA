class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        if right - left < 1:
            return [-1, -1]

        left = max(2, left)
        if left == 2 and right >= 3:
            return [2, 3]
        
        if left & 1 == 0:
            left += 1

        prev_prime = -1
        min_diff = float('inf')
        res = [-1, -1]

        def is_composite_witness(n: int, witness: int, d: int, s: int) -> bool:
            x = pow(witness, d, n)
            if x == 1 or x == n - 1:
                return False
            for _ in range(1, s):
                x = pow(x, 2, n)
                if x == n - 1:
                    return False
            return True

        def miller_rabin(n: int) -> bool:
            if n < 2:
                return False
            small_primes = [2, 3]
            for p in small_primes:
                if n == p:
                    return True
                if n % p == 0:
                    return False

            s = 0
            d = n - 1
            while d & 1 == 0:
                d >>= 1
                s += 1

            for witness in small_primes:
                if is_composite_witness(n, witness, d, s):
                    return False
            return True

        for candidate in range(left, right + 1, 2):
            if not miller_rabin(candidate):
                continue

            if prev_prime != -1:
                diff = candidate - prev_prime
                if diff == 2:
                    return [prev_prime, candidate]
                if diff < min_diff:
                    min_diff = diff
                    res = [prev_prime, candidate]

            prev_prime = candidate

        return res