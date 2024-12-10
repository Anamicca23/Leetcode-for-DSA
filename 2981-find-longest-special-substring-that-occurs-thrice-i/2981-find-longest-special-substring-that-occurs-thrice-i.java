import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        Map<String, Integer> mapie = new HashMap<>();

        // Populate the map with character-length frequency
        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int j = i; j < n; j++) {
                if (s.charAt(j) == s.charAt(i)) {
                    l++;
                    String key = s.charAt(i) + "," + l;
                    mapie.put(key, mapie.getOrDefault(key, 0) + 1);
                } else {
                    break;
                }
            }
        }

        // Find the maximum length
        int res = 0;
        for (Map.Entry<String, Integer> entry : mapie.entrySet()) {
            String key = entry.getKey();
            int freq = entry.getValue();
            int len = Integer.parseInt(key.split(",")[1]);

            if (freq >= 3 && len > res) {
                res = len;
            }
        }

        return res == 0 ? -1 : res;
    }
}
