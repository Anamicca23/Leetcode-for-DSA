class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //to keep track of length of array after removing element
        int count=0;
        //we will loop through entire nums array
        for(int i =0; i<nums.size(); i++){
            if(nums[i] != val)
            {
                nums[count++]=nums[i]; 
                //if element of nums is not equal to val we will modify nums 
            }
        }
        return count;
    }
};