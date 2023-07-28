class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // keep track of the next position to place an even number.
        int j=0;
        for(int i=0; i<nums.size(); i++){
            // it checks if the number is even by checking if 
            //nums[i] % 2 == 0. If it is even, it means it should 
            //be placed at the next available position for even numbers.
            if(nums[i]%2==0){
                swap(nums[i],nums[j++]);
                //After swapping, it increments j to update the next 
                //available position for even numbers.
            }
        }
        return nums;
        //Finally, it returns the modified nums vector as the sorted array by parity.
        /*
        The time complexity of the sortArrayByParity function is O(n), 
        where n is the size of the input vector nums. 
        This is because the function iterates through each element of the vector once, 
        performing constant-time operations.

The space complexity of the function is O(1) 
because it uses a constant amount of additional space. 
The function does not allocate any new data structures or dynamically 
resize the input vector. It performs the sorting in-place, 
modifying the original vector nums.
*/
    }
};