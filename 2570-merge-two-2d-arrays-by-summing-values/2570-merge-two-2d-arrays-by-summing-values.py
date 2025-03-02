class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        i, j = 0, 0
        result = []
        n1, n2 = len(nums1), len(nums2)
        
        while i < n1 or j < n2:
            if i < n1 and (j >= n2 or nums1[i][0] < nums2[j][0]):
                result.append(nums1[i])  # Add from nums1
                i += 1
            elif j < n2 and (i >= n1 or nums1[i][0] > nums2[j][0]):
                result.append(nums2[j])  # Add from nums2
                j += 1
            else:
                result.append([nums1[i][0], nums1[i][1] + nums2[j][1]])  # Merge common IDs
                i += 1
                j += 1
        
        return result