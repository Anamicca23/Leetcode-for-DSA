# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        def is_crit(x, y, z):
            return (y.val - x.val) * (y.val - z.val) > 0

        c = [0, 0]
        Min, i = inf, 1

        prev, curr, nxt = head, head.next, head.next.next        

        while nxt:
            if is_crit(prev, curr, nxt):
                if c[0]: Min = min(Min, i - c[c[1] > 0])
                c[c[0] > 0] = i

            prev, curr, nxt = curr, nxt, nxt.next
            i += 1

        return [[Min, c[1] - c[0]], [-1, -1]][not c[1]]