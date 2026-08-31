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
    public int[] nodesBetweenCriticalPoints(ListNode head) {

        int prev = head.val;
        int curr, next;
        ListNode temp = head.next;
        int mindis;
        int maxdis;
        int firstidx = 0, curridx = 0, previdx = 0;
        while (temp.next != null) {
            curr = temp.val;
            next = temp.next.val;
            temp = temp.next;
            if (curr < prev && curr < next || curr > prev && curr > next) {
                curridx = 1;
                firstidx = 1;
                prev = curr;
                break;
            }
            prev = curr;
        }
        if (firstidx == 0)
            return new int[] { -1, -1 };
        while (temp.next != null) {
            curr = temp.val;
            next = temp.next.val;
            temp = temp.next;
            curridx++;
            if (curr < prev && curr < next || curr > prev && curr > next) {
                previdx = curridx;
                prev = curr;
                break;
            }
            prev = curr;
        }
        if (previdx == 0)
            return new int[] { -1, -1 };
        mindis = maxdis = curridx - firstidx;
        while (temp.next != null) {
            curr = temp.val;
            next = temp.next.val;
            temp = temp.next;
            curridx++;
            if (curr < prev && curr < next || curr > prev && curr > next) {
                maxdis = curridx - firstidx;
                if ((curridx - previdx) < mindis)
                    mindis = curridx - previdx;
                previdx = curridx;
            }
            prev = curr;
        }
        return new int[] { mindis, maxdis };
    }
}