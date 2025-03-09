class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int len) {
        nums.insert(nums.end(), nums.begin(),nums.begin() + len - 1 );
        int countGroups = 0;
        int n = nums.size();
        int currentLength = 1;
        for (int i = 1; i < n; i++) {
        
            if (nums[i] != nums[i - 1]) {
                currentLength++;
            } else {
                currentLength = 1;
            }
            
           
            if (currentLength >= len) {
                countGroups++;
            }
        }
        
        return countGroups;
    }
};