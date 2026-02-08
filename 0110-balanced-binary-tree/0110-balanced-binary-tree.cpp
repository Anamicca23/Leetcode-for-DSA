class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = dfsHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }
};