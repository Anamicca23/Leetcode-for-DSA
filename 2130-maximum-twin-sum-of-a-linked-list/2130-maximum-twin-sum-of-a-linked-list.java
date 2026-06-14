/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    int res;
    ListNode left;

    public int pairSum(ListNode head) {
        left = head;
        dfs(head);
        return res;
    }

    private void dfs(ListNode right) {
        if (right.next != null)
            dfs(right.next);
        res = Math.max(res, left.val + right.val);
        left = left.next;
    }
}