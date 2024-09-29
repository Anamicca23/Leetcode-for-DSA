import java.util.*;

class AllOne {

    // Map to store the count of each key
    private Map<String, Integer> count;

    // TreeSet to maintain the keys sorted by their counts (first by count, then by key lexicographically)
    private TreeSet<Pair> set;

    // Constructor
    public AllOne() {
        count = new HashMap<>();
        set = new TreeSet<>((a, b) -> {
            if (a.count == b.count) {
                return a.key.compareTo(b.key); // If counts are equal, compare by key lexicographically
            }
            return Integer.compare(a.count, b.count); // Otherwise, compare by count
        });
    }

    // Increment the count of the key
    public void inc(String key) {
        int n = count.getOrDefault(key, 0); // Get current count, or default to 0
        if (n > 0) {
            set.remove(new Pair(n, key));   // Remove the old pair if it exists
        }
        count.put(key, n + 1);              // Increment the count
        set.add(new Pair(n + 1, key));      // Insert the new pair with the updated count
    }

    // Decrement the count of the key
    public void dec(String key) {
        int n = count.getOrDefault(key, 0); // Get current count
        if (n == 0) return;                 // If no such key, nothing to do

        set.remove(new Pair(n, key));       // Remove the old pair
        if (n == 1) {
            count.remove(key);              // If count is 1, remove the key from the map
        } else {
            count.put(key, n - 1);          // Decrement the count
            set.add(new Pair(n - 1, key));  // Insert the updated pair with the decremented count
        }
    }

    // Get the key with the maximum count
    public String getMaxKey() {
        if (!set.isEmpty()) {
            return set.last().key;  // The last element in TreeSet has the max count
        }
        return "";  // If no elements, return an empty string
    }

    // Get the key with the minimum count
    public String getMinKey() {
        if (!set.isEmpty()) {
            return set.first().key;  // The first element in TreeSet has the min count
        }
        return "";  // If no elements, return an empty string
    }

    // Helper class to represent pairs of (count, key)
    private static class Pair {
        int count;
        String key;

        Pair(int count, String key) {
            this.count = count;
            this.key = key;
        }

        // Must implement equals and hashCode to properly remove elements from the set
        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pair other = (Pair) obj;
            return count == other.count && Objects.equals(key, other.key);
        }

        @Override
        public int hashCode() {
            return Objects.hash(count, key);
        }
    }
}
