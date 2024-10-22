import java.util.PriorityQueue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    // Helper function to traverse the tree and calculate level sums
    public static void traverse(TreeNode root, int level, long[] sum, int[] size) {
        if (size[0] <= level) size[0]++;
        sum[level] += root.val;
        if (root.left != null) traverse(root.left, level + 1, sum, size);
        if (root.right != null) traverse(root.right, level + 1, sum, size);
    }

    // Main function to find the kth largest level sum
    public static long kthLargestLevelSum(TreeNode root, int k) {
        long[] sum = new long[100000];  // Array to store sums of each level
        int[] size = new int[1];  // Size array to track number of levels
        size[0] = 0;

        // Calculate sums of each level
        traverse(root, 0, sum, size);

        // If the number of levels is less than k, return -1
        if (size[0] < k) return -1;

        // Use a priority queue (min heap) to get the kth largest sum
        PriorityQueue<Long> minHeap = new PriorityQueue<>();

        for (int i = 0; i < size[0]; i++) {
            minHeap.add(sum[i]);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        return minHeap.peek();  // The kth largest element
    }
}
