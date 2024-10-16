import java.util.PriorityQueue;

class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder res = new StringBuilder();  // Resultant string
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((x, y) -> y[0] - x[0]); // Max-heap based on frequency

        if (a > 0) maxHeap.offer(new int[]{a, 'a'});
        if (b > 0) maxHeap.offer(new int[]{b, 'b'});
        if (c > 0) maxHeap.offer(new int[]{c, 'c'});

        while (!maxHeap.isEmpty()) {
            int[] curr = maxHeap.poll();  // Current character with max frequency
            int countCurr = curr[0];
            char charCurr = (char) curr[1];

            if (res.length() < 2 || res.charAt(res.length() - 1) != charCurr || res.charAt(res.length() - 2) != charCurr) {
                res.append(charCurr); // Append the character to the result
                countCurr--;  // Decrease frequency
                if (countCurr > 0) {
                    maxHeap.offer(new int[]{countCurr, charCurr}); // Reinsert if it still has occurrences
                }
            } else {
                if (maxHeap.isEmpty()) break;  // No other characters available
                
                int[] next = maxHeap.poll();  // Next character with max frequency
                int countNext = next[0];
                char charNext = (char) next[1];

                res.append(charNext);  // Append the next character
                countNext--;  // Decrease frequency
                if (countNext > 0) {
                    maxHeap.offer(new int[]{countNext, charNext}); // Reinsert next character
                }
                maxHeap.offer(new int[]{countCurr, charCurr});  // Reinsert current character
            }
        }

        return res.toString();
    }
}
