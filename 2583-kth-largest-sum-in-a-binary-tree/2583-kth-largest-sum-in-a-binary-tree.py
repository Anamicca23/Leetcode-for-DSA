# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        sum=[0]*100000
        sz=0
        def dfs(root, level):
            nonlocal sz
            if not root: return
            if sz<=level: sz+=1
            sum[level]+=root.val
            if root.left: dfs(root.left, level+1)
            if root.right: dfs(root.right, level+1)
        dfs(root, 0)
        if sz<k: return -1
        return heapq.nlargest(k, sum[:sz])[-1]
        