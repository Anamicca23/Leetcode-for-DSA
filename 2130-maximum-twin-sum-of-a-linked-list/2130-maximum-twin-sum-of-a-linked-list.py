# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        res, left = 0, head

        def dfs(right):
            nonlocal res, left
            if right.next: dfs(right.next)
            res = max(res, left.val + right.val)
            left = left.next
        
        dfs(head)
        return res        