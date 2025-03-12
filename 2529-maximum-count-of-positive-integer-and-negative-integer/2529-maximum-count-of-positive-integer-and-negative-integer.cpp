class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n,p=0;
        for(int c:nums){
            if(c>0){
                p++;
            }
            else if(c<0){
                n++;
            }
        }
        return (n>p)?n:p;
    }
};