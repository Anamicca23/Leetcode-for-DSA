class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int minThrehold = 0;
        int maxThrehold = nums[nums.size() - 1] - nums[0];

        while (minThrehold < maxThrehold) {
            int candidateThrehold = minThrehold + (maxThrehold - minThrehold) / 2; // middle threshold
            // check how many pairs we can pick with this threshold

            int pairs = 0;

            // greedily pick pairs
            for (int i = 1; i < nums.size(); ++i) {
                if (candidateThrehold >= nums[i] - nums[i - 1]) {
                    ++pairs;
                    ++i; // you have picked i and i -1, you can't pick [i + 1, i] pair anymore
                }
            }

            if (pairs >= p) { // we are being to loose on the threshold and have too many pairs, be more strict on the threhold
                maxThrehold = candidateThrehold;
            } else { // we are being too strict about threshold and we do not have enough pairs, be more loose on threshold
                minThrehold = candidateThrehold + 1;
            }
        }

        return minThrehold;
    }
};