class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        long long res = 0;
        while(l < r){
            int num = nums[r], pow = 1;
            res += num;
            while(num){
                num /= 10;
                pow *= 10;
            }
            res += nums[l] * pow;
            ++l; --r;
        }
        if(l == r) res += nums[l];
        return res;
    }
};