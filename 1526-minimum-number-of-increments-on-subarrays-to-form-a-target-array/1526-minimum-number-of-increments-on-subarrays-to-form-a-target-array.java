class Solution {
    public int minNumberOperations(int[] target) {
        int min = target[0]; // Start with the first element
        for (int i = 1; i < target.length; i++) {
            // Add only when there's an increase compared to the previous number
            min += Math.max(target[i] - target[i - 1], 0);
        }
        return min;
    }
}