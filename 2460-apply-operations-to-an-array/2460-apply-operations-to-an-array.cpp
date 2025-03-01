class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i+1 < nums.size(); ++i){
            if(nums[i] == nums[i+1]){  
                nums[i] = 2*nums[i]; 
                nums[i+1] = 0;
            }
        }
        int i = 0;
        for(auto n: nums){  
            if(n != 0) nums[i++] = n;
        }
        while(i < nums.size()) nums[i++] = 0;    
        
        return nums;
    }
};