class Solution:
    def countGoodTriplets(self, arr, a, b, c):
        good = 0
        n = len(arr)
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    if abs(arr[i] - arr[j]) <= a and \
                       abs(arr[j] - arr[k]) <= b and \
                       abs(arr[i] - arr[k]) <= c:
                        good += 1
        return good