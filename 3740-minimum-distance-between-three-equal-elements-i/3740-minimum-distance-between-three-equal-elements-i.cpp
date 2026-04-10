class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int len = nums.size();
        vector<int> last2(len, 0);
        int res = 300;

        for (int i = 0; i < len; i++) {
            int val = nums[i] - 1;
            int pos = i + 1, pack = last2[val];
            int old = pack & 255, cur = pack >> 8;

            last2[val] = cur | (pos << 8);

            if (old)
                res = min(res, (pos - old) << 1);
        }

        return -(res == 300) | res;
    }
};