class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two Pointer Approach
        int i = 0, j = 0;
        // Move non-zero elements to the beginning of the array
        while (j < nums.size()) {
            if (nums[j] == 0) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        // Fill the remaining positions with zeros
        while (i < nums.size()) {
            nums[i++] = 0;
        }
        //After the execution of the code,
        //all zeros in the array/list will be moved to the end, 
        //and the relative order of the non-zero elements will be preserved.
    }
   // TC:=O(n)
   // SC:=O(1)
};
