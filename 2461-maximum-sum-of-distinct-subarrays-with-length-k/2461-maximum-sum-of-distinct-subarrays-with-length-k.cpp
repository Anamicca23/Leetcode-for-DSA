class Solution {
private:
    long long sum = 0;
    int dupli = 0, cnt[100001] = {};
    void pushElement(int &num) {
        sum += num;
        if (++cnt[num] == 2) ++dupli;
    }
    void popElement(int &num) {
        sum -= num;
        if (--cnt[num] == 1) --dupli;
    }
        
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) pushElement(nums[i]);
        long long res = dupli ? 0 : sum;

        for (int i = 0; i < nums.size() - k; ++i) {
            popElement(nums[i]);
            pushElement(nums[i + k]);
            if (!dupli) res = max(res, sum);
        }

        return res;
    }
};