class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        prefixes = set()
        for num in arr1:
            while num and num not in prefixes:
                prefixes.add(num)
                num //= 10
        
        longest = 0
        for num in set(arr2):
            while num:
                if num in prefixes:
                    longest = max(longest, len(str(num)))
                    break

                num //= 10
        
        return longest