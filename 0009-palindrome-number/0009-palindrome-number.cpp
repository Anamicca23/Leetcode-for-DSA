class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long rsno=0,tmp=x;
        while(tmp!=0){
            int ls=tmp%10;
            rsno = rsno*10+ls;
            tmp/=10;
        }
        return (rsno==x);
    }
};