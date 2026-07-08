class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        m = len(queries)
        MOD = 10**9 + 7

        prefSum = [0] * (n + 1)
        prefVal = [0] * (n + 1)
        prefCnt = [0] * (n + 1)
        power = [1] * (n + 1)

        for i in range(1, n + 1):
            power[i] = (power[i - 1] * 10) % MOD

        for i in range(n):
            d = int(s[i])

            prefSum[i + 1] = prefSum[i] + d
            prefCnt[i + 1] = prefCnt[i] + (1 if d != 0 else 0)

            if d == 0:
                prefVal[i + 1] = prefVal[i]
            else:
                prefVal[i + 1] = (prefVal[i] * 10 + d) % MOD

        result = [0] * m

        for i in range(m):
            l, r = queries[i]

            length = prefCnt[r + 1] - prefCnt[l]

            start = prefVal[l]
            end = prefVal[r + 1]

            x = (end - (start * power[length]) % MOD + MOD) % MOD
            sm = prefSum[r + 1] - prefSum[l]

            result[i] = (x * sm) % MOD

        return result