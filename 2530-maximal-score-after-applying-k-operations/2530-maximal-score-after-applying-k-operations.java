class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : nums) {
            maxHeap.add(num);
        }
        
        long score = 0;
        for (int i = 0; i < k; i++) {
            int x = maxHeap.poll();
            score += x;
            if (x == 1) {
                score += (k - 1 - i);
                break;
            }
            maxHeap.add((x + 2) / 3);
        }
        
        return score;
    }
}
