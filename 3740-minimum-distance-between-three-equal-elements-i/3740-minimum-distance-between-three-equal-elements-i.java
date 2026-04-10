class Solution {
    public int minimumDistance(int[] nums) {
        int len = nums.length;
        int[] last2 = new int[len];
        int res = 300;

        for (int i = 0; i < len; i++) {
            int val = nums[i] - 1;
            int pos = i + 1, pack = last2[val];
            int old = pack & 255, cur = pack >> 8;

            last2[val] = cur | (pos << 8);

            if (old > 0)
                res = Math.min(res, (pos - old) << 1);
        }

        return res == 300 ? -1 : res;
    }
}