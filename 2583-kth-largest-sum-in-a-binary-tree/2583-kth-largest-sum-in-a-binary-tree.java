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
    private int exploreLevels(TreeNode root, int level, long[] level_to_sum) {
        level_to_sum[level] += root.val;
        int left_level = level;
        if (root.left != null) {
            left_level = exploreLevels(root.left, level + 1, level_to_sum);
        }
        int right_level = level;
        if (root.right != null) {
            right_level = exploreLevels(root.right, level + 1, level_to_sum);
        }
        return Math.max(left_level, right_level);
    }

    private void swap(long[] values, int left, int right) {
        long temp = values[left];
        values[left] = values[right];
        values[right] = temp;
    }

    private int partition(long[] values, int start, int end, int target) {
        int current = start;
        long pivot_value = values[start];
        for (int i = current + 1; i <= end; i++) {
            long value = values[i];
            if (value <= pivot_value) {
                swap(values, current + 1, i);
                current++;
            }
        }
        swap(values, start, current);
        return current;
    }

    private long largest(long[] values, int start, int end, int target) {
        int index = partition(values, start, end, target);
        if (index < target) {
            return largest(values, index + 1, end, target);
        } else if (index == target) {
            return values[index];
        } else {
            long pivot_value = values[index];
            while (index > target && values[index] == pivot_value) {
                index--;
            }
            return largest(values, start, index, target);
        }
    }

    public long kthLargestLevelSum(TreeNode root, int k) {
        long[] level_to_sum = new long[100001];
        int max_level = exploreLevels(root, 0, level_to_sum);
        if (k > (max_level + 1)) {
            return -1;
        }
        return largest(level_to_sum, 0, max_level, max_level + 1 - k);
    }
}