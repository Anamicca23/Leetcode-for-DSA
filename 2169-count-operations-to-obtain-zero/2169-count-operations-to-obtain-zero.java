class Solution {
        public int countOperations(int num1, int num2) {
        int cnt = 0;
        while (Math.min(num1, num2) > 0) {
            if (num1 < num2) {
                int tmp = num1;
                num1 = num2;
                num2 = tmp;
            }
            cnt += num1 / num2;
            num1 %= num2;
        }
        return cnt;
    }
}