# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    N = int(1e5) + 5

    def __init__(self):
        self.height = [0] * self.N
        self.maxHeight = [0] * self.N
        self.secMaxHeight = [0] * self.N
        self.level = [0] * self.N

    def calculateHeight(self, node: Optional[TreeNode], lvl: int) -> int:
        if not node:
            return 0
        self.level[node.val] = lvl
        h = max(self.calculateHeight(node.left, lvl + 1), self.calculateHeight(node.right, lvl + 1)) + 1
        self.height[node.val] = h

        if h > self.maxHeight[lvl]:
            self.secMaxHeight[lvl], self.maxHeight[lvl] = self.maxHeight[lvl], h
        elif h > self.secMaxHeight[lvl]:
            self.secMaxHeight[lvl] = h

        return h

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        self.calculateHeight(root, 0)
        results = []
        for q in queries:
            lvl = self.level[q]
            if self.height[q] == self.maxHeight[lvl]:
                results.append(self.secMaxHeight[lvl] + lvl - 1)
            else:
                results.append(self.maxHeight[lvl] + lvl - 1)
        return results
        