class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) {
            int count = 0;
            int sum = 0;
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    count++;
                    sum += i;
                    if (i != j) {
                        count++;
                        sum += j;
                    }       if (count > 4) break;
                }
            }
            if (count == 4) totalSum += sum;
        }
        return totalSum;
    }
};