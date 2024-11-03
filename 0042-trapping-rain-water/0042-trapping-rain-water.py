class Solution:
    def trap(self, height: list[int]) -> int:
        n, ret, max_val, idx = len(height), 0, 0, 0
        
        for i in range(n):
            if height[i] > max_val:
                max_val = height[i]
                idx = i

        left = 0
        for i in range(idx):
            left = max(left, height[i])
            ret += left - height[i]

        right = 0
        for i in range(n - 1, idx, -1):
            right = max(right, height[i])
            ret += right - height[i]

        return ret
