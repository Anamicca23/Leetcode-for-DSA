class Solution {
public:
    int totalMoney(int n) {
        int r=n/7,c=n%7;
        return r*(c+28)+(r*(r-1))/2*7+(c*(c+1))/2;
        }
};