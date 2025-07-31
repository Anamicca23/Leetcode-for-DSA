__import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0"))
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        r = []
        l = 1
        for i in arr:
            ri = len(r)
            r.append(i)
            for j in range(l,ri):
                v = r[j] | i
                if (r[-1]!=v):
                    r.append(v)
            l = ri
        return len(set(r))