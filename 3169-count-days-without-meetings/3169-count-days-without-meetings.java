class Solution {
    TreeMap<Integer, Integer> intervalTree = new TreeMap<>();
    int totalCoveredLength = 0;

    public int countDays(int days, int[][] meetings) {
        for (int i = 0; i < meetings.length; i++) {
            var from = meetings[i][0];
            var to = meetings[i][1];
            Map.Entry<Integer, Integer> entry = intervalTree.floorEntry(to);
            while (entry != null && entry.getValue() >= from) {
                int existingLeft = entry.getKey();
                int existingRight = entry.getValue();
                totalCoveredLength -= existingRight - existingLeft + 1;
                from = Math.min(existingLeft, from);
                to = Math.max(existingRight, to);
                // Remove existing one
                intervalTree.remove(existingLeft);
                // Initialize entry to next one lesser than newly created entry
                entry = intervalTree.floorEntry(to);
            }
            // At the end insert merged interval and update total count
            intervalTree.put(from, to);
            totalCoveredLength += to - from + 1;
        }

        return days - totalCoveredLength;
    }

}