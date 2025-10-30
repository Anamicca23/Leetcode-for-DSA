class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        finale = curr = 0
        for i in target:
            if i > curr:
                finale += i - curr
            curr = i
        return finale