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

    public int[] treeQueries(TreeNode root, int[] queries) {
        calculateHeight(root, 0);
        int[] results = new int[queries.length];
        
        for (int i = 0; i < queries.length; i++) {
            int q = queries[i];
            int lvl = level[q];
            results[i] = (height[q] == maxHeight[lvl] ? secMaxHeight[lvl] : maxHeight[lvl]) + lvl - 1;
        }
        
        return results;
    }
}