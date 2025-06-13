class Solution:
    def getCommon(self, nums1, nums2):
        mp = defaultdict(int)
        for num in nums1:
            mp[num] += 1
        for num in nums2:
            if mp[num] > 0:
                return num
        return -1