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
    int sum[100001]={0}, h=0;
    void dfs1(TreeNode*& root, int level){// compute level sum
        if (!root) return ;
        if (level>=h) h++;
        sum[level]+=root->val;
        dfs1(root->left, level+1);
        dfs1(root->right, level+1);
    }
    void dfs2(TreeNode*& root, int level){
        if (!root) return ;
        if (level+1<=h){
            int x=sum[level+1];
            bool L=(root->left), R=(root->right);
            x-=L?root->left->val:0;
            x-=R?root->right->val:0;
            if (L) root->left->val=x;// set childern's values
            if (R) root->right->val=x;
        }
        dfs2(root->left, level+1);
        dfs2(root->right, level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, 0);
        root->val=0;
        dfs2(root, 0);
        return root;
    }
};