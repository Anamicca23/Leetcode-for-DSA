class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long res = 0L;
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int a = nums[left++];
            int b = nums[right--];
            res += a * pow10(b) + b;
        }

        if (left == right) {
            res += nums[left];
        }

        return res;
    }

    // Helper to calculate 10^digits(b)
    private long pow10(int num) {
        long pow = 1;
        while (num > 0) {
            pow *= 10;
            num /= 10;
        }
        return pow;
    }
}