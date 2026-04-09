class Solution:
    MOD = 10**9 + 7
    def modpow(self, a: int, e: int) -> int:
        r = 1
        a %= self.MOD
        while e:
            if e & 1:
                r = (r * a) % self.MOD
            a = (a * a) % self.MOD
            e >>= 1
        return r

    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        B = int(math.sqrt(n)) + 1
        events = [[] for _ in range(B + 1)]
        for k in range(1, B + 1):
            events[k] = [[] for _ in range(k)]
        for l, r, k, v in queries:
            if k > B:
                i = l
                while i <= r:
                    nums[i] = (nums[i] * v) % self.MOD
                    i += k
            else:
                rem = l % k
                start = (l - rem) // k
                end = (r - rem) // k

                events[k][rem].append((start, v))

                maxT = (n - 1 - rem) // k
                if end + 1 <= maxT:
                    inv = self.modpow(v, self.MOD - 2)
                    events[k][rem].append((end + 1, inv))
        for k in range(1, B + 1):
            for rem in range(k):
                ev = events[k][rem]
                if not ev:
                    continue
                ev.sort()
                comp = []
                for t, val in ev:
                    if comp and comp[-1][0] == t:
                        comp[-1] = (t, comp[-1][1] * val % self.MOD)
                    else:
                        comp.append((t, val))
                cur = 1
                ptr = 0
                t = 0
                idx = rem

                while idx < n:
                    while ptr < len(comp) and comp[ptr][0] == t:
                        cur = (cur * comp[ptr][1]) % self.MOD
                        ptr += 1
                    nums[idx] = nums[idx] * cur % self.MOD
                    t += 1
                    idx += k
        ans = 0
        for x in nums:
            ans ^= x

        return ans