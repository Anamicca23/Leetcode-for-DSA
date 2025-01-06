class Solution:
    def minOperations(self, boxes: str) -> list[int]:
        n = len(boxes)
        ans = [0] * n
        for i in range(n):
            if boxes[i] == '1':
                for j in range(n):
                    ans[j] += abs(j - i)
        return ans
