/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) return root;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean odd = false;

        while (!q.isEmpty()) {
            int n = q.size();
            List<TreeNode> nodes = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                nodes.add(node);
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            if (odd) {
                int l = 0, r = n - 1;
                while (l < r) {
                    int temp = nodes.get(l).val;
                    nodes.get(l).val = nodes.get(r).val;
                    nodes.get(r).val = temp;
                    l++;
                    r--;
                }
            }
            odd = !odd;
        }
        return root;
    }
}
