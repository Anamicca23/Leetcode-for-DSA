class Solution {
    public char kthCharacter(long k, int[] arr) {
        int c = 0; k--;
        for (int i = 0; k != 0; i++, k >>= 1) c += ((int)(k & 1) & arr[i]);
        return (char)((c % 26) + 'a');
    }
}