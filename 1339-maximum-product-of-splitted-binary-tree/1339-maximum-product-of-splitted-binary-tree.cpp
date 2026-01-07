class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProductVal = 0;

    // First DFS: compute total sum
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS: compute subtree sums and maximize product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        // Try cutting above this node
        maxProductVal = max(
            maxProductVal,
            subSum * (totalSum - subSum)
        );

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProductVal % MOD;
    }
};