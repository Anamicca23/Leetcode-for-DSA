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

    Map<TreeNode, TreeNode> parent = new HashMap<>();
    Map<TreeNode, Integer> depth = new HashMap<>();
    int maxDepth = 0;

    private void dfs(TreeNode node, TreeNode par, int d) {
        if (node == null) return;

        parent.put(node, par);
        depth.put(node, d);
        maxDepth = Math.max(maxDepth, d);

        dfs(node.left, node, d + 1);
        dfs(node.right, node, d + 1);
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        dfs(root, null, 0);

        List<TreeNode> deepest = new ArrayList<>();
        for (TreeNode node : depth.keySet()) {
            if (depth.get(node) == maxDepth) {
                deepest.add(node);
            }
        }

        Set<TreeNode> curr = new HashSet<>(deepest);

        while (curr.size() > 1) {
            Set<TreeNode> next = new HashSet<>();
            for (TreeNode node : curr) {
                next.add(parent.get(node));
            }
            curr = next;
        }

        return curr.iterator().next();
    }
}