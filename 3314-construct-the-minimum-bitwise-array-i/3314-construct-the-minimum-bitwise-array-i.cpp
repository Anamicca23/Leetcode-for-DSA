class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ((n & (n - 1)) == 0);
    }
    
    int largestPowerOfTwoLessThan(int n) {
        if (n <= 1) return 0;
        int exponent = floor(log2(n));
        return 1 << exponent; // Equivalent to pow(2, exponent)
    }
    
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto n: nums){
            if(n == 2) ans.push_back(-1);
            else{
                int t = n, sum = 0;
                while(t > 0){
                    if(isPowerOfTwo(t+1)){
                        sum += t/2;
                        t = 0;
                    }else{
                        int d = largestPowerOfTwoLessThan(t);
                        sum += d;
                        t -= d;
                    }
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};