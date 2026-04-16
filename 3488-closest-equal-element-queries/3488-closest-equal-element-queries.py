class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        N = len(nums)
        ans = []
        first = {}
        record = {}

        for i in range(N):
            if nums[i] not in record:
                ans.append(inf)
                record[nums[i]] = i
                first[nums[i]] = i
            else:
                dist = i - record[nums[i]]
                ans.append(dist)
                ans[record[nums[i]]] = min(ans[record[nums[i]]], dist)
                record[nums[i]] = i
        for num in first:
            if first[num] != record[num]:
                dist = N - record[num] + first[num]
                ans[record[num]] = min(ans[record[num]], dist)
                ans[first[num]] = min(ans[first[num]], dist)

        res = []
        for index in queries:
            if ans[index] == inf:
                ans[index] = -1
            res.append(ans[index])

        return res
