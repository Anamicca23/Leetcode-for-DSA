class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        head = ListNode(0)
        temp = head
        
        while l1 or l2 or carry:
            sum = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
            temp.next = ListNode(sum % 10)
            carry = sum // 10
            
            temp = temp.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            
        return head.next
