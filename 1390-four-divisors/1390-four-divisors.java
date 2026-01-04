class Solution {
    public int sumFourDivisors(int[] nums) {
        int total = 0;
        for (int x : nums) {
            int cnt = 0;
            int sum = 0;
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    cnt++;
                    sum += i;
                    if (i != j) {
                        cnt++;
                        sum += j;
                    }
                    if (cnt > 4) break; // early stop
                }
            }
            if (cnt == 4) total += sum;
        }
        return total;
    }
}