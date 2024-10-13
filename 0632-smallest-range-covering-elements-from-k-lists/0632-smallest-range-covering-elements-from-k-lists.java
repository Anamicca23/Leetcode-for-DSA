import java.util.*;

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        // A list of iterators that keeps track of the current position in each list
        List<Iterator<Integer>> iterators = new ArrayList<>();
        for (List<Integer> list : nums) {
            iterators.add(list.iterator());
        }

        // Priority Queue to always get the minimum element from the iterators
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int maxVal = Integer.MIN_VALUE;

        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            int val = nums.get(i).get(0);
            minHeap.offer(new int[]{val, i});  // [value, index of the list]
            maxVal = Math.max(maxVal, val);
        }

        // Track the best range
        int rangeStart = 0, rangeEnd = Integer.MAX_VALUE;

        while (true) {
            int[] min = minHeap.poll();  // Get the smallest element
            int minVal = min[0];
            int listIdx = min[1];

            // If the current range is smaller than the best range, update it
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Move the iterator for the list that contributed the smallest element
            if (iterators.get(listIdx).hasNext()) {
                int nextVal = iterators.get(listIdx).next();
                minHeap.offer(new int[]{nextVal, listIdx});
                maxVal = Math.max(maxVal, nextVal);  // Update the max value seen so far
            } else {
                // If any of the lists runs out, we're done
                break;
            }
        }

        return new int[]{rangeStart, rangeEnd};
    }
}
