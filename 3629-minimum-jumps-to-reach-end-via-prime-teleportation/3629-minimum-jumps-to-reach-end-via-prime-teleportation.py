MAXV = 1000001
spf = [i for i in range(MAXV)]
spf[0] = 0
spf[1] = 1
i = 2
while i * i < MAXV:
    if spf[i] == i:
        j = i * i
        while j < MAXV:
            if spf[j] == j:
                spf[j] = i
            j += i
    i += 1


class Solution:
    def isPrime(self, x):
        return x >= 2 and spf[x] == x

    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        maxi = max(nums)
        primeSeen = [False] * (maxi + 1)
        for x in nums:
            if self.isPrime(x):
                primeSeen[x] = True
        mp = defaultdict(list)
        for i, val in enumerate(nums):
            if val == 1:
                continue

            x = val
            while x > 1:
                p = spf[x]
                if p <= maxi and primeSeen[p]:
                    mp[p].append(i)
                while x % p == 0:
                    x //= p
        dist = [-1] * n
        dist[0] = 0
        usedPrime = [False] * (maxi + 1)
        q = deque([0])
        while q:
            idx = q.popleft()
            if idx == n - 1:
                return dist[idx]
            nd = dist[idx] + 1
            if idx - 1 >= 0 and dist[idx - 1] == -1:
                dist[idx - 1] = nd
                q.append(idx - 1)
            if idx + 1 < n and dist[idx + 1] == -1:
                dist[idx + 1] = nd
                q.append(idx + 1)
            x = nums[idx]
            if self.isPrime(x) and not usedPrime[x]:
                usedPrime[x] = True
                for nextIdx in mp[x]:
                    if dist[nextIdx] == -1:
                        dist[nextIdx] = nd
                        q.append(nextIdx)
        return -1
