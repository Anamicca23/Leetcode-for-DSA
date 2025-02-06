class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hm;
        hm.reserve(n * (n - 1) / 2); // Pre-allocate space to reduce rehashing

        // Step 1: Compute products of all pairs and store their frequency
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int mul = nums[i] * nums[j];
                hm[mul]++;
            }
        }
        
        int total = 0;
        // Step 2: Count valid tuples based on frequency
        for (const auto &it: hm) {
            int count = it.second;
            if (count >= 2)
                total += count * (count - 1) / 2;  // Choose 2 pairs from count pairs
        }
        
        return total * 8;  // Each tuple (a, b, | c, d) can be arranged in 8 ways
    }
};