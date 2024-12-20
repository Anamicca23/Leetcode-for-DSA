/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        bool odd = false;
        
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> node(n);
            for (int i = 0; i < n; ++i) {
                node[i] = q.front(); q.pop();
                if (node[i]->left) q.push(node[i]->left);
                if (node[i]->right) q.push(node[i]->right);
            }
            if(odd){
                int l=0,r=n-1;
                while(l<r)swap(node[l++]->val,node[r--]->val);
            }
            odd = !odd;
        }
        return root;
    }
};