class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(s.count(nums[i] + diff) && s.count(nums[i] + 2 * diff))
            {
                count++;
            }
        }
        return count;
    }
};