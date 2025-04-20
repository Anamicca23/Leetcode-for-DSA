import java.util.*;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> freq = new HashMap<>();

        for (int a : answers) {
            freq.put(a, freq.getOrDefault(a, 0) + 1);
        }

        int count = 0;
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            int groupSize = k + 1;
            int groups = (v + k) / groupSize;
            count += groups * groupSize;
        }

        return count;
    }
}