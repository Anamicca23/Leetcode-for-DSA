class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        if n == 1:
            return sum(num % k == 0 for num in range(1, 10))

        part_pals = [str(num) for num in range(10**((n//2) - 1), 10**(n//2))]
        k_pals = []
        if n % 2 == 0:
            k_pals = [num + num[::-1] for num in part_pals]
        else:
            for mid in range(10):
                k_pals.extend([num + str(mid) + num[::-1] for num in part_pals])

        k_pals = [p for p in k_pals if int(p) % k == 0]
        perms = set(''.join(sorted(pal)) for pal in k_pals)

        cnt = 0
        for p in perms:
            freqs = Counter(p)
            cnt += ((n - freqs.get('0', 0)) * factorial(n - 1))//prod(map(factorial, freqs.values()))
        
        return cnt
   