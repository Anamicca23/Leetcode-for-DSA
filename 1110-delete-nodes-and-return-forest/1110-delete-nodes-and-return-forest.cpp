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

private:
    void unlinker(TreeNode* &root, unordered_map<int,bool> &del, vector<TreeNode*> &ans){
        if(!root) return;

        unlinker(root->left,del,ans);
        unlinker(root->right,del,ans);

        if(del[root->val]){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root = NULL;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_map<int,bool> del;
        for(int i : to_delete) del[i] = true;

        vector<TreeNode*> ans;
        unlinker(root,del,ans);
        if(root) ans.push_back(root);

        return ans;
    }
};