/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* currNode=head;
        ListNode* nextNode = head->next;
        while(nextNode){
            ListNode* temp = new ListNode(__gcd(currNode->val,nextNode->val));
            currNode->next=temp;
            temp->next = nextNode;
            currNode= nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};