class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        if (arr.length < 3) return false;
        for (int i = 0; i <= arr.length - 3; i++) {
            if ((arr[i] & 1) == 1 && (arr[i+1] & 1) == 1 && (arr[i+2] & 1) == 1)
                return true;
        }
        return false;
    }
}