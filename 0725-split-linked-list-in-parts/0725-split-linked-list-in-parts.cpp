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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L=0;
        while(curr){
            L++;curr = curr ->next;
        }
        int eachBucketNodes = L/k;
        int remainderNodes = L%k;
        vector<ListNode*>res(k,NULL);
        curr = head;
        ListNode* prev =NULL;
        for(int i =0; i<k; i++){
            res[i]=curr;
            for(int cnt =1; cnt<=eachBucketNodes + ( remainderNodes > 0?1:0);cnt++){
                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL)
              prev -> next = NULL;
             remainderNodes--;
        }
        return res;
    }
};