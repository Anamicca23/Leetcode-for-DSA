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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int left = 0;
        int right = m - 1;
        int down = n - 1;
        int top = 0;
        int dir = 0;
        int ct=0;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        
        vector<vector<int>>ans(n, vector<int> (m, -1));
        while(top <= down && left <= right && ct < v.size()) {
            if(dir == 0 && ct < v.size()) {
                for(int i = left; i <= right && ct < v.size(); i++) {
                    // cout << ct << endl;
                    ans[top][i]=v[ct];
                    ct++;
                }
                top++;
            } else if(dir == 1 && ct < v.size()) {
                for(int i = top; i <= down && ct < v.size(); i++) {
                    ans[i][right]=v[ct];
                    // cout << ct << endl;
                    ct++;
                }
                right--;
            } else if(dir == 2 && ct < v.size()) {
                for(int i = right; i >= left && ct < v.size(); i--) {
                    ans[down][i]=v[ct];
                    // cout << ct << endl;
                    ct++;
                }
                down--;
            } else if(dir == 3 && ct < v.size()) {
                for(int i = down; i >= top && ct < v.size(); i--) {
                    ans[i][left]=v[ct];
                    // cout << ct << endl;
                    ct++;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
        
    
};
 