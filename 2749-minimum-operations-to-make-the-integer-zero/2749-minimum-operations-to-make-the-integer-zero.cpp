class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num2==0) return popcount(unsigned(num1));
        long long x=num1;
        for(int k=1; k<36; k++){
            x-=num2;
            if (x<k) return -1;
            if (x>=0 && k>=popcount((unsigned long long)(x))) return k;
        }
        return -1;
    }
};