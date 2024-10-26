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
    static const int N = 1e5 + 5;
    int height[N] = {}, maxHeight[N] = {}, secMaxHeight[N] = {}, level[N] = {};

    int calculateHeight(TreeNode* node, int lvl) {
        if (!node) return 0;
        level[node->val] = lvl;
        int h = max(calculateHeight(node->left, lvl + 1), calculateHeight(node->right, lvl + 1)) + 1;
        height[node->val] = h;
        
        if (h > maxHeight[lvl]) tie(secMaxHeight[lvl], maxHeight[lvl]) = {maxHeight[lvl], h};
        else if (h > secMaxHeight[lvl]) secMaxHeight[lvl] = h;

        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calculateHeight(root, 0);
        vector<int> results;
        for (int q : queries) {
            int lvl = level[q];
            results.push_back((height[q] == maxHeight[lvl] ? secMaxHeight[lvl] : maxHeight[lvl]) + lvl - 1);
        }
        return results;
    }
};
