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
    int solve(TreeNode* root,int val){
      if(!root)return 0;
      val = 2*val + root->val;
      if(!root->left && !root->right)return val;
      return solve(root->left, val) + solve(root->right, val);
    }
    int sumRootToLeaf(TreeNode* root) {
       return solve(root,0);
    }
};