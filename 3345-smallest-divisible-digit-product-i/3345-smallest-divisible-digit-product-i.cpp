class Solution {
public:
    int productOfDigits(int num){
        int product = 1;
        while(num){
            product *= num % 10;
            num /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while(productOfDigits(n) % t != 0)n++;
        return n;
    }
};