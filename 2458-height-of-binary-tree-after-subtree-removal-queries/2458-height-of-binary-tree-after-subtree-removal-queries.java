import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    static final int N = 100005;
    int[] height = new int[N];
    int[] maxHeight = new int[N];
    int[] secMaxHeight = new int[N];
    int[] level = new int[N];

    public int calculateHeight(TreeNode node, int lvl) {
        if (node == null) return 0;
        level[node.val] = lvl;
        int h = Math.max(calculateHeight(node.left, lvl + 1), calculateHeight(node.right, lvl + 1)) + 1;
        height[node.val] = h;

        if (h > maxHeight[lvl]) {
            secMaxHeight[lvl] = maxHeight[lvl];
            maxHeight[lvl] = h;
        } else if (h > secMaxHeight[lvl]) {
            secMaxHeight[lvl] = h;
        }

        return h;
    }

    public List<Integer> treeQueries(TreeNode root, List<Integer> queries) {
        calculateHeight(root, 0);
        List<Integer> results = new ArrayList<>();
        for (int q : queries) {
            int lvl = level[q];
            if (height[q] == maxHeight[lvl]) {
                results.add(secMaxHeight[lvl] + lvl - 1);
            } else {
                results.add(maxHeight[lvl] + lvl - 1);
            }
        }
        return results;
    }
}
