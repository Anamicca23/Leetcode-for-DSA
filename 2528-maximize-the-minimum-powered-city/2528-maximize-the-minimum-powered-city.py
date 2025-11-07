class Solution:
    def maxPower(self, stations: list[int], r: int, k: int) -> int:
        def canAchieve(stations: list[int], r: int, k: int, target: int) -> bool:
            n = len(stations)
            add = [0] * n
            used = 0
            window_sum = sum(stations[:r + 1])

            for i in range(n):
                if i - r - 1 >= 0:
                    window_sum -= stations[i - r - 1] + add[i - r - 1]
                if i + r < n and i != 0:
                    window_sum += stations[i + r] + add[i + r]

                if window_sum < target:
                    need = target - window_sum
                    if used + need > k:
                        return False
                    used += need
                    add[min(n - 1, i + r)] += need
                    window_sum += need
            return True

        low, high = 0, sum(stations) + k
        ans = 0

        while low <= high:
            mid = (low + high) // 2
            if canAchieve(stations, r, k, mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        return ans