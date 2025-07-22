class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0, currentSum = 0, start = 0;
        unordered_set<int> seen;

        for (int end = 0; end < nums.size(); end++) {
            while (seen.find(nums[end]) != seen.end()) {
                seen.erase(nums[start]);
                currentSum -= nums[start];
                start++;
            }

            currentSum += nums[end];
            seen.insert(nums[end]);

            result = max(result, currentSum);
        }

        return result;
    }
};