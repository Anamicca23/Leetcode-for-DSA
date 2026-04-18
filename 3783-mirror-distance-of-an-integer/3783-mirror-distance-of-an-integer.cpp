class Solution {
public:
    int mirrorDistance(int n) {
        int copy = n;
        int rev = 0;
        while(n>0){
            rev = rev*10 + n%10;
            n/=10;
        }
        return abs(rev-copy);
    }
};