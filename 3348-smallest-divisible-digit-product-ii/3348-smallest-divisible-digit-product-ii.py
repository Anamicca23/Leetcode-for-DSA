class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        def build_end(req, size):
            res = []
            for f in range(9, 1, -1):
                while req % f == 0:
                    req //= f
                    res.append(str(f))
            if len(res) < size: res += ['1'] * (size - len(res))
            return "".join(res[::-1])        
        n = len(num)
        curr = t
        for f in [2, 3, 5, 7]:
            while curr % f == 0:
                curr //= f
        if curr != 1: return '-1'
        rem = [0] * (n + 1)
        rem[0] = t
        for i in range(n):
            if num[i] == '0': break
            rem[i + 1] = rem[i] // gcd(rem[i], int(num[i]))
        if rem[-1] == 1: return num
        z = num.find('0')
        start = z if z != -1 else n - 1
        for i in range(start, -1, -1):
            end_size = n - i - 1
            for d in range(int(num[i]) + 1, 10):
                last = build_end(rem[i] // gcd(rem[i], d), end_size)
                if len(last) == end_size: return num[:i] + str(d) + last
        
        return build_end(t, n + 1)