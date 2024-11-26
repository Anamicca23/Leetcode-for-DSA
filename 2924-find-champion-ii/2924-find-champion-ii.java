import java.util.*;

public class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] freq = new int[n];

        // Count incoming edges for each node
        for (int[] edge : edges) {
            int e = edge[1];
            freq[e]++;
        }

        int champ = -1;
        int count = 0;

        // Find the node with zero incoming edges
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                champ = i;
                count++;
                if (count > 1) {
                    return -1; // More than one node with zero incoming edges
                }
            }
        }

        return champ; // Return the champion or -1 if no unique champion exists
    }
}
