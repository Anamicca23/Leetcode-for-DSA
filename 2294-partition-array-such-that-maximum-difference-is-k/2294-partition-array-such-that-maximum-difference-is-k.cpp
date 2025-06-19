class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::bitset<100001> exists;
        int minV = nums[0];
        int maxV = nums[0];

        for (auto v: nums) {
            minV = std::min(minV, v);
            maxV = std::max(maxV, v);
            exists[v] = true;
        }

        int seq = 1;
        int start = minV;
        for (int v = minV; v <= maxV; ++v) {
            if (exists[v]) {
                if (v - start > k) {
                    start = v;
                    ++seq;
                }
            }
        }

        return seq;
    }
};