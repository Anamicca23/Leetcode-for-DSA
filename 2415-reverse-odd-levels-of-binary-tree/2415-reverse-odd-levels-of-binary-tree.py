from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        q = deque([root])
        odd = False

        while q:
            n = len(q)
            nodes = []
            for _ in range(n):
                node = q.popleft()
                nodes.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if odd:
                l, r = 0, n - 1
                while l < r:
                    nodes[l].val, nodes[r].val = nodes[r].val, nodes[l].val
                    l += 1
                    r -= 1
            odd = not odd

        return root
