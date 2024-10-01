class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainderCount = new int[k];
        for (int num : arr) {
            int rem = ((num % k) + k) % k; 
            remainderCount[rem]++;
        }
        if (remainderCount[0] % 2 != 0) return false; 
        for (int i = 1; i <= k / 2; i++) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }
        return true;
    }
}