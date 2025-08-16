class Solution {
public:
    int maximum69Number (int num) {
        for (int i = 1000; i > 0; i /= 10) {
            if ((num / i) % 10 == 6) {
                num += 3 * i;
                break;
            }
        }
        return num;
    }
};