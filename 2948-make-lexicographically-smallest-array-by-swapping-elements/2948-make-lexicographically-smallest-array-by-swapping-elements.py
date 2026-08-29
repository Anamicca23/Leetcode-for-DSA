class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)
        sorted_nums = sorted(nums)
        group = {}
        groupId = {}
        pos = {}
        id = 1
        group[id] = [sorted_nums[0]]
        groupId[sorted_nums[0]] = id
        for i in range(1, n):
            if sorted_nums[i] - sorted_nums[i - 1] > limit:
                id += 1
            group.setdefault(id, []).append(sorted_nums[i])
            groupId[sorted_nums[i]] = id
        for i in range(n):
            grp = groupId[nums[i]]
            p = pos.get(grp, 0)
            nums[i] = group[grp][p]
            pos[grp] = p + 1
        return nums